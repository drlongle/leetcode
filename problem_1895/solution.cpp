/*
1895. Largest Magic Square
Medium

A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum,
and both diagonal sums are all equal. The integers in the magic square do not have to be distinct.
Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square
that can be found within this grid.

Example 1:
Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12

Example 2:
Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 10^6
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j, int K) {
        int sum = 0, sum2 = 0;
        for (int k = 0; k < K; ++k) {
            sum += grid[i+k][j+k];
        }
        for (int k = 0; k < K; ++k) {
            sum2 += grid[i+K-k-1][j+k];
        }
        if (sum != sum2)
            return false;
        for (int k = 0; k < K; ++k) {
            int s = 0;
            for (int x = 0; x < K; ++x) {
                s += grid[i+k][j+x];
            }
            if (s != sum)
                return false;

            s = 0;
            for (int x = 0; x < K; ++x) {
                s += grid[i+x][j+k];
            }
            if (s != sum)
                return false;
        }
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int k = min(m, n); k >= 1; --k) {
            for (int i = 0; i + k <= m; ++i) {
                for (int j = 0; j + k <= n; ++j) {
                    if (check(grid, i, j, k))
                        return k;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 3
    grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    cout << sol.largestMagicSquare(grid) << endl;

    grid = {{5,1,3,1},{9,3,3,1},{1,3,3,8}};
    cout << sol.largestMagicSquare(grid) << endl;

    return 0;
}
