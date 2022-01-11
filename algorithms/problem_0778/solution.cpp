/*
778. Swim in Rising Water
Hard

On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:
Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

Note:
2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].
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

class Solution {
public:
    int swimInWater(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        struct Entry {
            Entry(int i, int j, int t): x(i), y(j), time(t) {}
            int x, y;
            int time;
        };
        auto compare = [&] (Entry& e1, Entry& e2) {
            return grid[e1.x][e1.y] > grid[e2.x][e2.y];
        };
        array<array<int, 2>, 4> offsets{-1, 0, 1, 0, 0, -1, 0, 1};
        priority_queue<Entry, vector<Entry>, decltype(compare)> pq(compare);
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        pq.emplace(0, 0, grid[0][0]);
        visited[0][0] = grid[0][0];
        int res = INT_MAX;
        while (!pq.empty()) {
            auto [x, y, time] = pq.top();
            pq.pop();
            if (x == m - 1 && y == n - 1) {
                res = min(res, time);
            }
            for (auto& offset: offsets) {
                int nx = x + offset[0], ny = y + offset[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] > time) {
                    pq.emplace(nx, ny, max(time, grid[nx][ny]));
                    visited[nx][ny] = time;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 3
    grid = {{0,2},{1,3}};;
    cout << sol.swimInWater(grid) << endl;

    // Output: 16
    grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout << sol.swimInWater(grid) << endl;

    return 0;
}
