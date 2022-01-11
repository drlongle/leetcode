/*
323. Number of Connected Components in an Undirected Graph
Medium

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0, 1] is the same as [1, 0] and thus will not appear together in edges.
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    void DFS(int n) {
        visited[n] = true;
        for (int nei: graph[n]) {
            if (!visited[nei])
                DFS(nei);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        graph.clear();
        visited.clear();
        graph.resize(n);
        visited.resize(n, false);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++res;
                DFS(i);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
