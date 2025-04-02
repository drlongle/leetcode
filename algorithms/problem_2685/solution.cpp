/*
2685. Count the Number of Complete Components
Medium

You are given an integer n. There is an undirected graph with n vertices,
numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i]
= [ai, bi] denotes that there exists an undirected edge connecting vertices ai
and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path
between any two vertices, and no vertex of the subgraph shares an edge with a
vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between
every pair of its vertices.

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of
this graph are complete.

Example 2:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since
there is an edge between every pair of two vertices. On the other hand, the
component containing vertices 3, 4, and 5 is not complete since there is no edge
between vertices 4 and 5. Thus, the number of complete components in this graph
is 1.

Constraints:
    1 <= n <= 50
    0 <= edges.length <= n * (n - 1) / 2
    edges[i].length == 2
    0 <= ai, bi <= n - 1
    ai != bi
    There are no repeated edges.
*/

#include <algorithm>
#include <atomic>
#include <bit>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<unordered_set<int>> g;
    vector<bool> visited;
    vector<int> component;

    void dfs(int i) {
        component.push_back(i);
        for (int u : g[i]) {
            if (!visited[u]) {
                visited[u] = true;
                dfs(u);
            }
        }
    }

    bool checkComplete(vector<int> &component) {
        for (int i : component) {
            for (int u : component) {
                if (u != i && g[i].count(u) == 0)
                    return false;
            }
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        g.resize(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].insert(v);
            g[v].insert(u);
        }
        visited = vector<bool>(n, false);
        int result{};
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                component.clear();
                dfs(i);
                result += checkComplete(component);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n;
    vector<vector<int>> edges;

    n = 6, edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    // cout << sol.countCompleteComponents(n, edges) << endl;

    // Output: 1
    n = 6, edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    cout << sol.countCompleteComponents(n, edges) << endl;

    return 0;
}
