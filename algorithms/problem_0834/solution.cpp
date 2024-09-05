/*
834. Sum of Distances in Tree
Hard

https://leetcode.com/problems/sum-of-distances-in-tree/

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n
- 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi]
indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances
between the ith node in the tree and all other nodes.

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

Example 2:
Input: n = 1, edges = []
Output: [0]

Example 3:
Input: n = 2, edges = [[1,0]]
Output: [1,1]

Constraints:
1 <= n <= 3 * 10^4
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.
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
    vector<vector<int>> graph;
    vector<int> distance;
    vector<bool> visited;
    unordered_map<int, pair<int, int>>
        counts; // number of child nodes and distance sum to child nodes

    pair<int, int> dfs1(int i) {
        visited[i] = true;
        pair<int, int> r{1, 0};

        for (int ne : graph[i]) {
            if (!visited[ne]) {
                auto t = dfs1(ne);
                r.first += t.first;
                r.second += t.first + t.second;
            }
        }
        counts[i] = r;

        return r;
    }

    void dfs2(int i, int nodes, int dist) {
        visited[i] = true;

        for (int ne : graph[i]) {
            if (!visited[ne]) {
                nodes += counts[ne].first;
                dist += counts[ne].first + counts[ne].second;
            }
        }
        distance[i] = dist;

        for (int ne : graph[i]) {
            if (!visited[ne]) {
                // Add the new edge for the current node and all visited nodes
                // but subtract the distance of the child node to be visited.
                dfs2(ne, nodes + 1 - counts[ne].first,
                     (nodes + 1 - counts[ne].first) + dist -
                         (counts[ne].first + counts[ne].second));
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        graph.clear();
        graph.resize(n);
        visited.clear();
        visited.resize(n, false);
        distance.clear();
        distance.resize(n, 0);
        counts.clear();

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs1(0);

        visited.clear();
        visited.resize(n, false);

        dfs2(0, 0, 0);

        return distance;
    }
};

int main() {
    vector<vector<int>> edges;
    vector<int> res;
    int n;

    // Output: {8,12,6,10,10,10}
    {
        Solution sol;
        n = 6, edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
        res = sol.sumOfDistancesInTree(n, edges);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: {0}
    {
        Solution sol;
        n = 1, edges = {};
        res = sol.sumOfDistancesInTree(n, edges);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: {1,1}
    {
        Solution sol;
        n = 2, edges = {{1, 0}};
        res = sol.sumOfDistancesInTree(n, edges);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
