/*
1976. Number of Ways to Arrive at Destination
Medium

You are in a city that consists of n intersections numbered from 0 to n - 1 with
bi-directional roads between some intersections. The inputs are generated such
that you can reach any intersection from any other intersection and that there
is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui,
vi, timei] means that there is a road between intersections ui and vi that takes
timei minutes to travel. You want to know in how many ways you can travel from
intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest
amount of time. Since the answer may be large, return it modulo 10^9 + 7.

Example 1:
Input: n = 7, roads =
[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to
intersection 6 is 7 minutes. The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Example 2:
Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1,
and it takes 10 minutes.

Constraints:
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 10^9
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
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

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<vector<pair<int, int>>> graph;
    int countPaths(int n, vector<vector<int>> &roads) {
        graph.resize(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], c = road[2];
            graph[u].emplace_back(v, c);
            graph[v].emplace_back(u, c);
        }

        vector<long long> dists(n, LONG_MAX);
        ;
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        dists[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dists[node])
                continue;
            for (auto [u, c] : graph[node]) {
                if (d + c < dists[u]) {
                    dists[u] = dists[node] + c;
                    ways[u] = ways[node];
                    pq.emplace(dists[u], u);
                } else if (d + c == dists[u]) {
                    ways[u] = (ways[u] + ways[node]) % 1000000007ull;
                }
            }
        }

        return ways[n - 1];
    }
};

int main() {
    Solution sol;
    int n;
    vector<vector<int>> roads;

    n = 7, roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
                    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    cout << sol.countPaths(n, roads) << endl;

    return 0;
}
