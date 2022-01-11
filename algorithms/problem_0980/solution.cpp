/*
980. Unique Paths III
Difficulty: Hard

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending
square, that walk over every non-obstacle square exactly once.

Example 1:
Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:
Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:
Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
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

class Solution {
public:
    
    int explore(int i, int j, vector<vector<int>>& grid) {
        if (grid[i][j] == 2)
            return empty == 1;
        
        int res = 0;
        grid[i][j] = -1;
        --empty;
        
        array<array<int, 2>, 4> offsets{-1, 0, 1, 0, 0, -1, 0, 1};
        for (auto& offset: offsets) {
            int next_i = i + offset[0];
            int next_j = j + offset[1];
            if (next_i >= 0 && next_i < rows && next_j >= 0 && next_j < columns
                    && grid[next_i][next_j] != -1)
                res += explore(next_i, next_j, grid);
        }
        
        grid[i][j] = 0;
        ++empty;
        
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        empty = 0;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                if (grid[i][j] >= 0) {
                    ++empty;
                    if (grid[i][j] == 1) {
                        start_i = i, start_j = j;
                    }
                }


        return explore(start_i, start_j, grid);
    }
    
private:
    int rows, columns;
    int start_i, start_j, empty;
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<int>> grid;
    
    // Expected: 2
    grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    
    // Expected: 4
    grid = {{1,0,0,0},{0,0,0,0},{0,0,0, 2}};

    // Expected: 0
    //grid = {{0,1},{2,0}};
    
    cout << "Result: " << sol.uniquePathsIII(grid) << endl;
    
    return 0;
}
