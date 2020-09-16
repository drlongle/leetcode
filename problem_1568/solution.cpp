/*
1568. Minimum Number of Days to Disconnect Island
Hard

Given a 2D grid consisting of 1s (land) and 0s (water).  An island is a maximal 4-directionally (horizontal or vertical)
connected group of 1s. The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

Example 1:
Input: grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}}
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid{1}{1} and grid{0}{2} to water and get 2 disconnected island.

Example 2:
Input: grid = {{1,1}}
Output: 2
Explanation: Grid of full water is also disconnected ({{1,1}} -> {{0,0}}), 0 islands.

Example 3:
Input: grid = {{1,0,1,0}}
Output: 0

Example 4:
Input: grid = {{1,1,0,1,1},
               {1,1,1,1,1},
               {1,1,0,1,1},
               {1,1,0,1,1}}
Output: 1

Example 5:
Input: grid = {{1,1,0,1,1},
               {1,1,1,1,1},
               {1,1,0,1,1},
               {1,1,1,1,1}}
Output: 2

Constraints:
1 <= grid.length, grid{i}.length <= 30
grid{i}{j} is 0 or 1.
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

    int count_islands(vector<vector<int>> grid, bool count_neighs) {
        int islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1)
                    continue;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                grid[i][j] = -1;
                ++islands;
                while (!q.empty()) {
                    auto& [x, y] = q.front();
                    ++xcnt[x], ++ycnt[y];
                    int cnt = 0;
                    for (auto& offset: offsets) {
                        int nx = x + offset[0], ny = y + offset[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0) {
                            ++cnt;
                            if (grid[nx][ny] == 1) {
                                q.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    if (count_neighs && cnt)
                        res = min(res, cnt);
                    q.pop();
                    ++cells;
                }
            }
        }


        return islands;
    }

    int m, n, cells, res;
    map<int, int> xcnt, ycnt;
    vector<vector<int>> offsets;

    Solution(): offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
    { }

    void back_track(vector<vector<int>>& grid, int changes) {
        if (changes >= res)
            return;
        int islands = count_islands(grid, false);
        if (islands > 1)
            res = min(res, changes);
        if (changes + 1 >= res)
            return;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    back_track(grid, changes + 1);
                    grid[i][j] = 1;
                }
            }
        }
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), cells = 0, res = numeric_limits<int>::max();;
        int islands = count_islands(grid, true);

        if (islands != 1)
            return 0;
        if (cells <= 2)
            return cells;

        for (auto& [x, cnt]: xcnt) {
            if (x != xcnt.begin()->first && x != xcnt.rbegin()->first)
                res = min(res, cnt);
        }

        for (auto& [y, cnt]: ycnt) {
            if (y != ycnt.begin()->first && y != ycnt.rbegin()->first)
                res = min(res, cnt);
        }
        back_track(grid, 0);

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    
    // Output: 2
    grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    cout << sol.minDays(grid) << endl;

    // Output: 2
    grid = {{1,1}};
    cout << sol.minDays(grid) << endl;
    
    // Output: 0
    grid = {{1,0,1,0}};
    cout << sol.minDays(grid) << endl;

    // Output: 1
    grid = {
            {1,1,0,1,1},
            {1,1,1,1,1},
            {1,1,0,1,1},
            {1,1,0,1,1}};
    cout << sol.minDays(grid) << endl;

    // Output: 2
    grid = {{1,1,0,1,1},
    {1,1,1,1,1},
    {1,1,0,1,1},
    {1,1,1,1,1}};
    cout << sol.minDays(grid) << endl;

    // Output: 1
    grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << sol.minDays(grid) << endl;

    // Output: 1
    grid = {
            {1,1,1,1,0,1,1,1,1},
            {1,1,1,1,0,1,1,1,1},
            {0,0,0,1,0,1,0,0,0},
            {1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1}};
    cout << sol.minDays(grid) << endl;

    return 0;
}
