/*
1377. Frog Position After T Seconds
Hard

Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from the vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex. 

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting directly the vertices fromi and toi.

Return the probability that after t seconds the frog is on the vertex target.

Example 1:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666 
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666. 

Example 2:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1. 

Example 3:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6
Output: 0.16666666666666666

Constraints:
1 <= n <= 100
edges.length == n-1
edges[i].length == 2
1 <= edges[i][0], edges[i][1] <= n
1 <= t <= 50
1 <= target <= n
Answers within 10^-5 of the actual value will be accepted as correct.
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
    struct Entry {
        Entry(int i, int e, double p): id(i), elapsed(e), prob(p) {}
        int id;
        int elapsed;
        double prob;
    };
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, unordered_set<int>> graph;
        vector<bool> visited(n+1, false);
        for (auto& edge: edges) {
            graph[edge[0]].emplace(edge[1]);
            graph[edge[1]].emplace(edge[0]);
        }

        queue<Entry> q;
        q.emplace(1, 0, 1.0);
        visited[1] = true;
        while (!q.empty()) {
            Entry& e = q.front();
            int sz = graph[e.id].size() - (e.id == 1 ? 0 : 1);
            if (e.id == target) {
                if (sz == 0)
                    return (t >= e.elapsed ? e.prob : 0);
                else
                    return (t == e.elapsed ? e.prob : 0);
            }

            for (auto neigh: graph[e.id]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.emplace(neigh, e.elapsed + 1, e.prob / sz);
                }
            }
            q.pop();
        }
        return 0.0;
    }
};

int main() {
    Solution sol;
    int n, t, target;
    vector<vector<int>> edges;

    // Output: 0.16666666666666666 
    n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 2, target = 4;
    cout << sol.frogPosition(n, edges, t, target) << endl;

    // Output: 0.3333333333333333
    n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 1, target = 7;
    cout << sol.frogPosition(n, edges, t, target) << endl;

    // Output: 0.16666666666666666
    n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 20, target = 6;
    cout << sol.frogPosition(n, edges, t, target) << endl;

    // Output: 0.0
    n = 8, edges = {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}}, t = 7, target = 7;
    cout << sol.frogPosition(n, edges, t, target) << endl;
    
    return 0;
}
