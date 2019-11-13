/*
1254. Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally
connected group of 0s and a closed island is an island totally (all left, top, right, bottom)
surrounded by 1s.

Return the number of closed islands.
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
    int rows, cols;
    using Array = array<int, 2>;
    array<Array, 4> offsets{Array{0, 1}, Array{0, -1}, Array{1, 0}, Array{-1, 0}};
    
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto& p = q.front();
            grid[p.first][p.second] = 1;
            for (auto& offset: offsets) {
                pair<int, int> pp = {p.first + offset[0], p.second + offset[1]};
                if (pp.first >= 0 && pp.first < rows && pp.second >= 0 && pp.second < cols &&
                    grid[pp.first][pp.second] == 0)
                    q.emplace(pp);
            }

            q.pop();
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        rows = grid.size();
        cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            if (grid[i][0] == 0)
                bfs(grid, i, 0);
            if (grid[i][cols-1] == 0)
                bfs(grid, i, cols-1);
        }
        for (int i = 0; i < cols; ++i) {
            if (grid[0][i] == 0)
                bfs(grid, 0, i);
            if (grid[rows-1][i] == 0)
                bfs(grid, rows-1, i);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    ++res;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    
    grid = {{0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0},
            {1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0}};

    cout << "Result: " << sol.closedIsland(grid) << endl;
    
    return 0;
}
