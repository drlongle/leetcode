/*
463. Island Perimeter
Easy

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
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
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j])
                    continue;
                for (auto& offset: offsets) {
                    int ni = i + offset[0];
                    int nj = j + offset[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 0) {
                        ++cnt;
                    }
                }
            }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 16
    grid = {{0,1,0,0},
            {1,1,1,0},
            {0,1,0,0},
            {1,1,0,0}};
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}
