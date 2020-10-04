/*
785. Is Graph Bipartite?
Medium

Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that
every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes
i and j exists.  Each node is an integer between 0 and graph.length - 1. There are no self edges or parallel edges:
graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.

Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<unordered_set<int>> G;
    vector<int> color;

    bool dfs(int curr, int d) {
        if (color[curr] >= 0 && color[curr] != d)
            return false;
        color[curr] = d;
        for (int nid: G[curr]) {
            if (color[nid] >= 0) {
                if (color[nid] != 1-d)
                    return false;
            } else if (!dfs(nid, 1 - d))
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        G.resize(n);
        color.resize(n, -1);

        for (int i = 0; i < n; ++i) {
            for (int j: graph[i]) {
                G[i].emplace(j);
                G[j].emplace(i);
            }
        }

        for (int id = 0; id < n; ++id)
            if (color[id] < 0 && !dfs(id, 0))
                return false;

        return true;
    }
};

int main() {
    vector<vector<int>> graph;

    {
        Solution sol;
        graph = {{1,3}, {0,2}, {1,3}, {0,2}};
        cout << boolalpha << sol.isBipartite(graph) << endl;
    }

    {
        Solution sol;
        graph = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
        cout << boolalpha << sol.isBipartite(graph) << endl;
    }

    return 0;
}
