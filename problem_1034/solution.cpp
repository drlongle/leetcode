/*
1034. Coloring A Border
Medium

Given a 2-dimensional grid of integers, each value in the grid represents the color of the grid square at that location.

Two squares belong to the same connected component if and only if they have the same color and are next to each other in any of the 4 directions.

The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).

Given a square at location (r0, c0) in the grid and a color, color the border of the connected component of that square with the given color, and return the final grid.

Example 1:
Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
Output: [[3, 3], [3, 2]]

Example 2:
Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
Output: [[1, 3, 3], [2, 3, 3]]

Example 3:
Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]

Note:
1 <= grid.length <= 50
1 <= grid[0].length <= 50
1 <= grid[i][j] <= 1000
0 <= r0 < grid.length
0 <= c0 < grid[0].length
1 <= color <= 1000
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
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.emplace(r0, c0);
        visited[r0][c0] = true;
        int origin_color = grid[r0][c0];
        while (!q.empty()) {
            auto& p = q.front();
            int i = p.first;
            int j = p.second;
            for (auto& offset: offsets) {
                int ni = i + offset[0];
                int nj = j + offset[1];

                if (ni < 0 || ni >= m || nj < 0 || nj >= n || (grid[ni][nj] != origin_color && !visited[ni][nj]))
                    grid[i][j] = color;
                else if (!visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q.emplace(ni, nj);
                }
            }
            q.pop();
        }
        return grid;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    int r0, c0, color;

    // Output: {{3, 3}, {3, 2}}
    grid = {{1,1},{1,2}}, r0 = 0, c0 = 0, color = 3;

    // Output: {{1, 3, 3}, {2, 3, 3}}
    //grid = {{1,2,2},{2,3,2}}, r0 = 0, c0 = 1, color = 3;

    // Output: {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}}
    grid = {{1,1,1},{1,1,1},{1,1,1}}, r0 = 1, c0 = 1, color = 2;

    // Output: [[1,1,1,1,1,2},[1,2,1,1,1,2},[1,1,1,1,1,2}}
    //grid = {{1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2}};
    //r0 = 1, c0 = 3, color = 1;
    
    grid = sol.colorBorder(grid, r0, c0, color);
    for (auto& row: grid) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
