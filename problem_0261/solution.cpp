/*
261. Graph Valid Tree
Medium

Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes),
write a function to check whether these edges make up a valid tree.

Example 1:
Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Example 2:
Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0,1] is the same as [1,0] and thus will not appear together in edges.
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> state;

    bool DFS(int i, int prev) {
        if (state[i] != 0)
            return false;
        state[i] = 1;
        for (int nei: graph[i]) {
            if (nei != prev && !DFS(nei, i))
                return false;
        }
        state[i] = 2;
        return true;
    }

    unordered_map<int, unordered_set<int>> graph;

    bool validTree(int n, vector<vector<int>>& edges) {
        for (auto& edge: edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        state.resize(n, 0);
        if (!DFS(0, -1))
            return false;
        for (int i = 0; i < n; ++i) {
            if (state[i] != 2)
                return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> edges;
    int n;

    // Output: true
    {
        Solution sol;
        n = 5, edges = {{0,1}, {0,2}, {0,3}, {1,4}};
        cout << boolalpha << sol.validTree(n, edges) << endl;
    }

    // Output: false
    {
        Solution sol;
        n = 5, edges = {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}};
        cout << boolalpha << sol.validTree(n, edges) << endl;
    }

    return 0;
}
