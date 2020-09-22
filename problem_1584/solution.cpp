/*
1584. Min Cost to Connect All Points
Medium

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Example 3:
Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4

Example 4:
Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000

Example 5:
Input: points = [[0,0]]
Output: 0

Constraints:
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
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

using namespace std;

class Solution {
public:
    struct Edge {
        Edge(int i_, int j_, int d): i(i_), j(j_), dist(d) {
        }

        bool operator<(const Edge& other) const {
            return dist < other.dist;
        }
        int i, j, dist;
    };

    vector<int> roots;

    int get_root(int n) {
        while (true) {
            int next = roots[n];
            if (next == n)
                break;
            n = next;
        }
        return n;
    }

    void join_root(int n, int root) {
        while (true) {
            int next = roots[n];
            if (next == root)
                break;
            roots[n] = root;
            n = next;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        roots.resize(sz);
        iota(begin(roots), end(roots), 0);
        vector<Edge> edges;
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(i, j, d);
            }
        }
        sort(begin(edges), end(edges));
        int res = 0, cnt = 0;
        for (auto& e: edges) {
            int ri = get_root(e.i);
            int rj = get_root(e.j);
            if (ri == rj)
                continue;
            res += e.dist;
            if (++cnt == sz - 1)
                break;
            if (ri < rj)
                join_root(e.j, ri);
            else
                join_root(e.i, rj);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points;

    // Output: 20
    points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << sol.minCostConnectPoints(points) << endl;

    // Output: 18
    points = {{3,12},{-2,5},{-4,1}};
    cout << sol.minCostConnectPoints(points) << endl;

    // Output: 4
    points = {{0,0},{1,1},{1,0},{-1,1}};
    cout << sol.minCostConnectPoints(points) << endl;

    // Output: 4000000
    points = {{-1000000,-1000000},{1000000,1000000}};
    cout << sol.minCostConnectPoints(points) << endl;

    // Output: 0
    points = {{0,0}};
    cout << sol.minCostConnectPoints(points) << endl;

    return 0;
}
