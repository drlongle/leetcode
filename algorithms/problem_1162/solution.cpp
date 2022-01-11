/*
1162. As Far from Land as Possible
Medium

Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.

Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.

Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.
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
    array<array<int, 2>, 4> offsets{-1, 0, 1, 0, 0, -1, 0, 1};
    int maxDistance(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        int rows = grid.size();
        if (!rows)
            return -1;
        int columns = grid[0].size();
        if (!columns)
            return -1;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j]) {
                    q.emplace(i, j, 0);
                    grid[i][j] = -1;
                }
            }
        if (q.empty() || static_cast<int>(q.size()) == rows*columns)
            return -1;
        int res = 0;
        while (!q.empty()) {
            auto& tup = q.front();
            int dist = get<2>(tup);
            res = max(res, dist);
            for (auto& offset: offsets) {
                int i = get<0>(tup) + offset[0];
                int j = get<1>(tup) + offset[1];
                if (i >= 0 && i < rows && j >= 0 && j < columns && grid[i][j] == 0) {
                    q.emplace(i, j, dist + 1);
                    grid[i][j] = -1;
                }
            }
            q.pop();
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 2
    grid = {{1,0,1},{0,0,0},{1,0,1}};

    // Output: 4
    //grid =  {{1,0,0},{0,0,0},{0,0,0}};

    cout << "Result: " << sol.maxDistance(grid) << endl;
    
    return 0;
}
