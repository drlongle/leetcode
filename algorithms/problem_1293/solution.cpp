/*
1293. Shortest Path in a Grid with Obstacles Elimination
Hard

Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move
up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner
(m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk
return -1. 

Example 1:

Input:
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]],
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).


Example 2:
Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.

Constraints:
grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0
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
    struct Cell {
        int val;
        set<int> counts;
    };
    struct Visit {
        int i, j, k, steps;
    };
    vector<vector<int>> offsets{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int M, N;
    int shortestPath(vector<vector<int>>& grid, int K) {
        M = grid.size();
        N = grid[0].size();
        vector<vector<Cell>> cells(M, vector<Cell>(N));
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j) {
                cells[i][j].val = grid[i][j];
            }
        queue<Visit> q;
        q.emplace(Visit{0, 0, 0, 0});
        int res = -1;
        while (q.size()) {
            auto v = q.front();
            q.pop();
            if (v.i == M -1 && v.j == N-1)
                res = res < 0 ? v.steps : min(res, v.steps);
            if (res >= 0 && v.steps >= res)
                continue;
            for (auto& offset: offsets) {
                int i = v.i + offset[0], j = v.j + offset[1];
                if (i >= 0 && i < M && j >= 0 && j < N && (i != 0 || j != 0) &&
                    !cells[i][j].counts.count(v.k)) {
                    if (cells[i][j].val && v.k == K)
                        continue;
                    cells[i][j].counts.emplace(v.k);
                    q.emplace(Visit{i, j, cells[i][j].val != 0 ? v.k+1 : v.k, v.steps+1});
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    int k;

    // Output: 6
    grid = 
        {{0,0,0},
         {1,1,0},
         {0,0,0},
         {0,1,1},
         {0,0,0}};
    k = 1;

    grid = {{0,1,1}, {1,1,1}, {1,0,0}}, k = 1;

    // Output: 65
    grid = {{0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,0},{1,0,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1},{1,0,0,1,1,1,1,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,1,0,1,1},{1,1,0,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,1,1,0},{0,1,1,0,1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1},{0,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,0,0,0,1,0},{0,0,0,0,1,0,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,1},{1,0,0,0,0,0,1,0,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1},{1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,0,0,0,1},{1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0},{1,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,0,0},{1,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1},{1,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1},{0,0,0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1},{0,1,0,0,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,1},{1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,1,1,1,1,1,0,1},{0,1,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,1,1,1,0,1,0,0,1,0,0,0,1},{0,1,0,0,1,1,1,0,1,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0},{0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1},{0,0,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,1,0,1,0,0,0,1,1,1,1,0,1,0,1,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0},{0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,0,1,1,0,1,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0},{1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0},{0,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,1,0},{0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,1,1},{1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1},{0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0,1},{1,1,1,0,1,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,0,0}};
    k = 510;
    
    cout << "Result: " << sol.shortestPath(grid, k) << endl;

    return 0;
}
