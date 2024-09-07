/*
2699. Modify Graph Edge Weights
Hard

https://leetcode.com/problems/modify-graph-edge-weights/

You are given an undirected weighted connected graph containing n nodes labeled
from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi]
indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight
(wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive
integer values in the range [1, 2 * 109] so that the shortest distance between
the nodes source and destination becomes equal to an integer target. If there
are multiple modifications that make the shortest distance between source and
destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it
is possible to make the shortest distance from source to destination equal to
target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive
weights.

Example 1:
Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0,
destination = 1, target = 5 Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making
the distance from 0 to 1 equal to 5.

Example 2:
Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target =
6 Output: [] Explanation: The graph above contains the initial edges. It is not
possible to make the distance from 0 to 2 equal to 6 by modifying the edge with
weight -1. So, an empty array is returned.

Example 3:
Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0,
destination = 2, target = 6 Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance
from 0 to 2 as 6.

Constraints:
1 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= ai, bi < n
wi = -1 or 1 <= wi <= 10^7
ai != bi
0 <= source, destination < n
source != destination
1 <= target <= 10^9
The graph is connected, and there are no self-loops or repeated edges
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
    static constexpr long long INF = 1e9;
    int runDijkstra(int n, int source, int dest,
                    vector<vector<pair<int, int>>> &graph) {
        vector<int> dist(n, INF);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        dist[source] = 0;
        heap.emplace(0, source);
        while (!heap.empty()) {
            auto [d, u] = heap.top();
            heap.pop();
            if (d > dist[u])
                continue;
            for (auto &[nei, wei] : graph[u]) {
                if (d + wei < dist[nei]) {
                    dist[nei] = d + wei;
                    heap.emplace(d + wei, nei);
                }
            }
        }

        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges,
                                           int source, int destination,
                                           int target) {
        vector<vector<pair<int, int>>> graph(n);

        // Step 1: Build the graph, excluding edges with -1 weights
        for (const auto &edge : edges) {
            if (edge[2] != -1) {
                graph[edge[0]].emplace_back(edge[1], edge[2]);
                graph[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        // Step 2: Compute the initial shortest distance from source to
        // destination
        int currentShortestDistance =
            runDijkstra(n, source, destination, graph);
        if (currentShortestDistance < target) {
            return vector<vector<int>>();
        }

        bool matchesTarget = (currentShortestDistance == target);

        // Step 3: Iterate through each edge to adjust its weight if necessary
        for (auto &edge : edges) {
            if (edge[2] != -1)
                continue; // Skip edges with already known weights

            // Set edge weight to a large value if current distance matches
            // target, else set to 1
            edge[2] = matchesTarget ? INF : 1;
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);

            // Step 4: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                int newDistance = runDijkstra(n, source, destination, graph);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>();
    }
};

int main() {
    Solution sol;
    int n, source, destination, target;
    vector<vector<int>> edges;

    edges = {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}}, source = 0, n = 5,
    destination = 1, target = 5;
    sol.modifiedGraphEdges(n, edges, source, destination, target);

    return 0;
}
