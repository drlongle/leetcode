/*
1091. Shortest Path in Binary Matrix
Difficulty: Medium

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it
is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are
different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right. 
If such a path does not exist, return -1.


Example 1:
Input: [[0,1],[1,0]]
Output: 2

Example 2:
Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct Cell {
    int x, y, hops;
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ssize = grid.size();
        if (grid[0][0] || grid[ssize-1][ssize-1])
            return -1;
        vector<vector<int>> offsets{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        queue<Cell> visits;
        visits.push({0, 0, 1});
        while (!visits.empty()) {
            Cell cell = visits.front();
            visits.pop();
            if (cell.x == ssize-1 && cell.y == ssize-1)
                return cell.hops;
            for (auto& offset: offsets) {
                int n_x = cell.x + offset[0];
                int n_y = cell.y + offset[1];
                if (n_x >= 0 && n_x < ssize && n_y >= 0 && n_y < ssize && grid[n_x][n_y] == 0) {
                    grid[n_x][n_y] = 1;
                    visits.push({n_x, n_y, cell.hops + 1});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Expected: 2
    grid = {{0,1},{1,0}};

    // Expected: 4
    //grid = {{0,0,0},{1,1,0},{1,1,0}};

    cout << "Result: " << sol.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}

