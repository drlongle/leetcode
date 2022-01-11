/*
1219. Path with Maximum Gold
Medium

In a gold mine grid of size m * n, each cell in this mine has an integer representing the
amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.

Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
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
    int collectGold(vector<vector<int>>& grid, int i, int j) {
        int temp = grid[i][j];
        int res = 0;
        grid[i][j] = 0;
        array<array<int, 2>, 4> offsets{-1, 0, 1, 0, 0, -1, 0, 1};
        for (auto& offset: offsets) {
            int new_i = i + offset[0];
            int new_j = j + offset[1];
            if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < columns &&
                grid[new_i][new_j] > 0) {
                res = max(res, collectGold(grid, new_i, new_j));
            }
        }
        grid[i][j] = temp;
        
        return res + temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        int res = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                if (grid[i][j])
                    res = max(res, collectGold(grid, i, j));
        return res;
    }
    
    int rows, columns;
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output = 24
    grid = {{0,6,0},{5,8,7},{0,9,0}};
    
    // Output = 28
    grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};

    cout << "Result: " << sol.getMaximumGold(grid) << endl;
    
    return 0;
}
