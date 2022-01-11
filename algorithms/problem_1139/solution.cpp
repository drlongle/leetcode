/*
1139. Largest 1-Bordered Square
Medium

Given a 2D grid of 0s and 1s, return the number of elements in the largest square
subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

Example 1:
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9

Example 2:
Input: grid = [[1,1,0,0]]
Output: 1
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();
        if (cols == 0)
            return 0;
        vector<vector<int>> height(rows, vector<int>(cols, 0));
        vector<vector<int>> width(rows, vector<int>(cols, 0));
        for (int i = rows-1; i >= 0; --i) {
            for (int j = cols-1; j >= 0; --j) {
                if (grid[i][j]) {
                    height[i][j] = 1 + ((i < rows -1) ? height[i+1][j] : 0);
                    width[i][j] = 1 + ((j < cols -1) ? width[i][j+1] : 0);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int edge = min(height[i][j], width[i][j]);
                for (int k = 1; k <= edge; ++k) {
                    if (width[i+k-1][j] >= k && height[i][j+k-1] >= k)
                        res = max(res, k*k);
                }
            }
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid;

    // Expected: 9
    grid = {{1,1,1},{1,0,1},{1,1,1}};

    // Expected: 1
    //grid = {{1,1,0,0}};

    // 54 / 84 test cases passed.
    // Expected: 4
    //grid = {{1,1,1},{1,1,0},{1,1,1},{0,1,1},{1,1,1}};
    
    cout << "Result: " << sol.largest1BorderedSquare(grid) << endl;
        
    return 0;
}

