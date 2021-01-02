/*
286. Walls and Gates
Medium

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you
may assume that the distance to a gate is less than 2147483647. Fill each empty room with the distance
to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example:
Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
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
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0)
            return;
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0)
                    q.emplace(i, j);
            }
        }
        vector<vector<int>> offsets{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!q.empty()) {
            auto& [x, y] = q.front();
            int dist = rooms[x][y] + 1;
            for (auto& offset: offsets) {
                int nx = x + offset[0], ny = y + offset[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && rooms[nx][ny] >= 0 && rooms[nx][ny] > dist) {
                    rooms[nx][ny] = dist;
                    q.emplace(nx, ny);
                }
            }
            q.pop();
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rooms;

    rooms = {{2147483647,-1,0,2147483647},
             {2147483647,2147483647,2147483647,-1},
             {2147483647,-1,2147483647,-1},
             {0,-1,2147483647,2147483647}};
    sol.wallsAndGates(rooms);

    return 0;
}
