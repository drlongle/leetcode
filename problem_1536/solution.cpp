/*
1536. Minimum Swaps to Arrange a Binary Grid
Medium

Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

Example 1:
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Example 2:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 200
grid[i][j] is 0 or 1
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
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= 0 && grid[i][j] == 0; --j)
                ++vals[i];
        }
        int res = 0;
        for (int i = 0; i < n-1; ++i) {
            int thres = n - i - 1, index = -1;
            for (int j = i; j < n; ++j) {
                if (vals[j] >= thres) {
                    index = j;
                    break;
                }
            }
            if (index < 0)
                return -1;
            res += (index - i);
            for (int j = index; j > i; --j)
                vals[j] = vals[j-1];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 3
    grid = {{0,0,1},{1,1,0},{1,0,0}};
    cout << sol.minSwaps(grid) << endl;

    // Output: -1
    grid = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    cout << sol.minSwaps(grid) << endl;

    // Output: 0
    grid = {{1,0,0},{1,1,0},{1,1,1}};
    cout << sol.minSwaps(grid) << endl;

    return 0;
}
