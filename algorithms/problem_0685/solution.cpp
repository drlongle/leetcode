/*
685. Redundant Connection II
Hard

In this problem, a rooted tree is a directed graph such that, there is exactly
one node (the root) for which all other nodes are descendants of this node, plus
every node has exactly one parent, except for the root node which has no
parents.

The given input is a directed graph that started as a rooted tree with n nodes
(with distinct values from 1 to n), with one additional directed edge added. The
added edge has two different vertices chosen from 1 to n, and was not an edge
that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a
pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where
ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree
of n nodes. If there are multiple answers, return the answer that occurs last in
the given 2D-array.

Example 1:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:
Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]

Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
*/

#include <algorithm>
#include <atomic>
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int n, cnt;
    vector<vector<int>> graph;
    vector<int> seen;

    bool dfs(int n) {
        if (seen[n])
            return false;
        ++cnt;
        seen[n] = true;
        for (int nei : graph[n])
            dfs(nei);
        return true;
    }

    bool checkGraph(vector<vector<int>> &edges, int ignored) {
        graph.clear();
        seen.clear();
        graph.resize(n + 1);
        seen.resize(n + 1);
        cnt = 0;
        vector<int> cand(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            if (i != ignored) {
                graph[edges[i][0]].push_back(edges[i][1]);
                cand[edges[i][1]] = 0;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (cand[i]) {
                dfs(i);
                break;
            }
        }
        return cnt == n;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        n = edges.size();
        for (int i = n - 1; i >= 0; --i) {
            if (checkGraph(edges, i)) {
                return edges[i];
            }
        }

        return {};
    }
};

int main() {
    Solution sol;

    return 0;
}
