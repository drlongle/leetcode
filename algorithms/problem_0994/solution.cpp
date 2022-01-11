/*
994. Rotting Oranges
Difficulty: Easy

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to
a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a
fresh orange.  If this is impossible, return -1 instead.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
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

struct BadOrange {
    BadOrange(int _x, int _y, int _interval): x(_x), y(_y), interval(_interval) {}
    int x, y, interval;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = - 1;
        int fresh = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        queue<BadOrange> bads;
        for (size_t x = 0; x < rows; ++x) {
            for (size_t y = 0; y < columns; ++y) {
                switch (grid[x][y]) {
                    case 0:
                        break;
                    case 1:
                        ++fresh;
                        break;
                    case 2:
                        bads.emplace(x, y, 0);
                }
            }
        }
        
        if (fresh == 0)
            return 0;
        array<array<int,2>, 4> offsets = {1,0,-1,0,0,1,0,-1};
        while (fresh > 0 && bads.size() > 0) {
            BadOrange& bad = bads.front();
            for (const auto& offset: offsets) {
                int x = bad.x + offset[0];
                int y = bad.y + offset[1];
                if (x >= 0 && x < rows && y >= 0 && y <= columns && grid[x][y] == 1) {
                    --fresh;
                    bads.emplace(x, y, bad.interval + 1);
                    grid[x][y] = 2;
                    res = max(res, bad.interval + 1);
                }
            }
            bads.pop();
        }
        if (fresh > 0)
            return -1;
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<int>> grid;
    
    // Expected: 4
    grid = {{2,1,1},{1,1,0},{0,1,1}};
    
    // Expected: -1
    //grid = {{2,1,1},{0,1,1},{1,0,1}};

    // Expected: 0
    //grid = {{0,2}};
    
    cout << "Result: " << sol.orangesRotting(grid) << endl;
    return 0;
}
