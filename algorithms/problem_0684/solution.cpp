/*
684. Redundant Connection
Medium

In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
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
#include <memory>
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
    void dfs(int n, int prev) {
        stack.push_back(n);
        if (states[n] == 1) {
            if (cycles.empty()) {
                for (int i = stack.size() - 2; i >= 0; --i) {
                    cycles.emplace(set<int>{stack[i], stack[i+1]});
                    if (stack[i] == n)
                        break;
                }
            }
            states[n] = 2;
            stack.pop_back();
            return;
        }
        states[n] = 1;
        for (int next: edges[n]) {
            if (next == prev)
                continue;
            dfs(next, n);
        }
        stack.pop_back();
        states[n] = 2;
    }
    
    vector<int> states, stack;
    set<set<int>> cycles;
    unordered_map<int, unordered_set<int>> edges;
    vector<int> findRedundantConnection(vector<vector<int>>& graph) {
        int n = graph.size();
        states.resize(n+1, 0);
        edges.clear();
        for (auto& edge: graph) {
            edges[edge[0]].emplace(edge[1]);
            edges[edge[1]].emplace(edge[0]);
        }
        
        dfs(1, 0);
        for (auto it = graph.rbegin(); it != graph.rend(); ++it) {
            set<int> key(it->begin(), it->end());
            if (cycles.count(key)) {
                sort(it->begin(), it->end());
                return *it;
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    
    // Output: {2,3}
    edges = {{1,2}, {1,3}, {2,3}};

    // Output: {1,4}
    edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};

    // Output: {1,4}
    edges = {{1,2},{2,3},{1,5},{3,4},{1,4}};

    // Output: {2,8}
    edges = {{2,7},{7,8},{3,6},{2,5},{6,8},{4,8},{2,8},{1,8},{7,10},{3,9}};

    auto res = sol.findRedundantConnection(edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
