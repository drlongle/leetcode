/*
797. All Paths From Source to Target
Medium

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Note:
The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    unordered_map<int, unordered_set<int>> parents;
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int node) {
        for (int neigh: graph[node]) {
            parents[neigh].emplace(node);
            if (parents[neigh].size() == 1)
                dfs(graph, neigh);
        }
    }

    void trace_back(vector<int>& path) {
        int node = path.back();
        if (node == 0) {
            reverse(begin(path), end(path));
            res.emplace_back(path);
            reverse(begin(path), end(path));            
        } else {
            for (int p: parents[node]) {
                path.emplace_back(p);
                trace_back(path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        vector<int> path(1, graph.size()-1);
        trace_back(path);

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph;

    // Output: {{0,1,3},{0,2,3}} 
    graph = {{1,2}, {3}, {3}, {}}; 
    auto res = sol.allPathsSourceTarget(graph);
    for (auto& r: res) {
        copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
