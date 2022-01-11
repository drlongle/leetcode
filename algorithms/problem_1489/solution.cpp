/*
1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
Hard

Given a weighted undirected connected graph with n vertices numbered from 0 to n-1,
and an array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional
and weighted edge between nodes fromi and toi. A minimum spanning tree (MST) is a subset
of the edges of the graph that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the minimum spanning tree (MST)
of the given graph. An MST edge whose deletion from the graph would cause the MST weight
to increase is called a critical edge. A pseudo-critical edge, on the other hand,
is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

Example 1:
Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:
Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:
Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

Constraints:
2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti <= 1000
All pairs (fromi, toi) are distinct.
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
    int get_root(int i) {
        while (i != roots[i])
            i = roots[i];
        return i;
    }

    void set_root(int i, int root) {
        while (root != roots[i]) {
            int temp = roots[i];
            roots[i] = root;
            i = temp;
        }
    }

    struct Compare {
        Compare(vector<vector<int>>& e): edges(e)
        {
        }

        bool operator()(int i, int j) const {
            return edges[i][2] > edges[j][2];
        }
        vector<vector<int>>& edges;
    };

    int mst(priority_queue<int, vector<int>, Compare>& pq, vector<vector<int>>& edges, int cnt, int n, bool included = false) {
        int res = 0;
        while (pq.size()) {
            int index = pq.top();
            pq.pop();
            auto& edge = edges[index];
            int x = edge[0], y = edge[1];
            int root_x = get_root(x), root_y = get_root(y);
            if (root_x == root_y)
                continue;
            res += edge[2];
            if (res > optimal)
                return numeric_limits<int>::max();
            if (root_x < root_y)
                set_root(y, root_x);
            else
                set_root(x, root_y);
            if (included)
                pseudo_criticals[index] = true;
            if (++cnt == n-1) {
                while (pq.size())
                    pq.pop();
                break;
            }
        }
        return (cnt == n-1) ? res : numeric_limits<int>::max();
    }
    vector<vector<int>> res;
    vector<int> roots;
    int optimal;
    vector<bool> pseudo_criticals;
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        roots.resize(n+1);
        res.resize(2);
        res[0].clear(), res[1].clear();
        int sz = edges.size();
        pseudo_criticals.resize(sz, false);
        optimal = numeric_limits<int>::max();
        Compare compare(edges);
        priority_queue<int, vector<int>, Compare> pq(compare);
        for (int i = 0; i < sz; ++i) {
            pq.push(i);
        }
        iota(begin(roots), end(roots), 0);
        optimal = mst(pq, edges, 0, n, true);
        
        for (int i = 0; i < sz; ++i) {
            auto& edge = edges[i];
            int x = edge[0], y = edge[1], cost = edge[2];
            if (cost > optimal)
                continue;
            for (int j = 0; j < sz; ++j) {
                if (j != i)
                    pq.push(j);
            }
            iota(begin(roots), end(roots), 0);
            if (mst(pq, edges, 0, n) > optimal) {
                res[0].push_back(i);
                continue;
            }
            if (pseudo_criticals[i]) {
                res[1].push_back(i);
                continue;
            }
            iota(begin(roots), end(roots), 0);

            if (x < y)
                set_root(y, x);
            else
                set_root(x, y);
            for (int j = 0; j < sz; ++j) {
                if (j != i)
                    pq.push(j);
            }
            if (cost + mst(pq, edges, 1, n) == optimal)
                res[1].push_back(i);

        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges, res;
    int n;

    // Output: {{0,1},{2,3,4,5}}
    n = 5, edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    res = sol.findCriticalAndPseudoCriticalEdges(n, edges);
    for (int i = 0; i <= 1; ++i) {
        copy(begin(res[i]), end(res[i]), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: {{},{0,1,2,3}}
    n = 4, edges = {{0,1,1},{1,2,1},{2,3,1},{0,3,1}};
    res = sol.findCriticalAndPseudoCriticalEdges(n, edges);
    for (int i = 0; i <= 1; ++i) {
        copy(begin(res[i]), end(res[i]), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    n = 6, edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    res = sol.findCriticalAndPseudoCriticalEdges(n, edges);
    for (int i = 0; i <= 1; ++i) {
        copy(begin(res[i]), end(res[i]), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
