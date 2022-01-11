/*
1594. Maximum Non Negative Product in a Matrix
Medium

You are given a rows x cols matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step,
you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner
(rows - 1, cols - 1), find the path with the maximum non-negative product. The product of a path is the product of
all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 10^9 + 7. If the maximum product is negative return -1.

Notice that the modulo is performed after getting the maximum product.

Example 1:
Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.

Example 2:
Input: grid = [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).

Example 3:
Input: grid = [[1, 3],
               [0,-4]]
Output: 0
Explanation: Maximum non-negative product is in bold (1 * 0 * -4 = 0).

Example 4:
Input: grid = [[ 1, 4,4,0],
               [-2, 0,0,1],
               [ 1,-1,1,1]]
Output: 2
Explanation: Maximum non-negative product is in bold (1 * -2 * 1 * -1 * 1 * 1 = 2).

Constraints:
1 <= rows, cols <= 15
-4 <= grid[i][j] <= 4
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    struct Cell {
        Cell(): pos(-1), neg(0) {}
        long long pos, neg;
    };

    static constexpr int MOD = 1000000007;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<Cell>> dp(m, vector<Cell>(n));
        if (grid[0][0] >= 0)
            dp[0][0].pos = grid[0][0];
        else
            dp[0][0].neg = grid[0][0];
        bool has_zero = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                has_zero |= grid[i][j] == 0;
                if (i != 0 || j != 0) {
                    if (grid[i][j] >= 0) {
                        dp[i][j].pos = grid[i][j] * max((i > 0 ? dp[i-1][j].pos : -1), (j > 0 ? dp[i][j-1].pos : -1));
                        dp[i][j].neg = grid[i][j] * min((i > 0 ? dp[i-1][j].neg : 0), (j > 0 ? dp[i][j-1].neg : 0));
                    } else {
                        if (i > 0 && dp[i-1][j].neg < 0)
                            dp[i][j].pos = grid[i][j] * dp[i-1][j].neg;
                        if (j > 0 && dp[i][j-1].neg < 0)
                            dp[i][j].pos = max(dp[i][j].pos, grid[i][j] * dp[i][j-1].neg);
                        if (i > 0 && dp[i-1][j].pos >= 0)
                            dp[i][j].neg = grid[i][j] * dp[i-1][j].pos;
                        if (j > 0 && dp[i][j-1].pos >= 0)
                            dp[i][j].neg = min(dp[i][j].neg, grid[i][j] * dp[i][j-1].pos);
                    }
                }
            }
        }

        if (dp[m-1][n-1].pos >= 0)
            return dp[m-1][n-1].pos % MOD;
        return has_zero ? 0 : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: -1
    grid = {{-1,-2,-3},
            {-2,-3,-3},
            {-3,-3,-2}};
    cout << sol.maxProductPath(grid) << endl;

    // Output: 8
    grid = {{1,-2,1},
            {1,-2,1},
            {3,-4,1}};
    cout << sol.maxProductPath(grid) << endl;

    // Output: 0
    grid = {{1, 3},
            {0,-4}};
    cout << sol.maxProductPath(grid) << endl;

    // Output: 2
    grid = {{ 1, 4,4,0},
            {-2, 0,0,1},
            { 1,-1,1,1}};
    cout << sol.maxProductPath(grid) << endl;

    // Output: 0
    grid = {{-1,3,0},{3,-2,3},{-1,1,-4}};
    cout << sol.maxProductPath(grid) << endl;

    // Output: 19215865
    grid = {{2,1,3,0,-3,3,-4,4,0,-4},
            {-4,-3,2,2,3,-3,1,-1,1,-2},
            {-2,0,-4,2,4,-3,-4,-1,3,4},
            {-1,0,1,0,-3,3,-2,-3,1,0},
            {0,-1,-2,0,-3,-4,0,3,-2,-2},
            {-4,-2,0,-1,0,-3,0,4,0,-3},
            {-3,-4,2,1,0,-4,2,-4,-1,-3},
            {3,-2,0,-4,1,0,1,-3,-1,-1},
            {3,-4,0,2,0,-2,2,-4,-2,4},
            {0,4,0,-3,-4,3,3,-1,-2,-2}};
    cout << sol.maxProductPath(grid) << endl;

    return 0;
}
