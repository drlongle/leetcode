/*
1504. Count Submatrices With All Ones
Medium

Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

Example 1:
Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Example 2:
Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.

Example 3:
Input: mat = [[1,1,1,1,1,1]]
Output: 21

Example 4:
Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
Output: 5

Constraints:
1 <= rows <= 150
1 <= columns <= 150
0 <= mat[i][j] <= 1
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
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), cnt = 0;
        vector<vector<int>> height(m, vector<int>(n, 0)), width(m, vector<int>(n, 0));
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                height[i][j] = mat[i][j] ? (1 + (i < m-1 ? height[i+1][j] : 0)) : 0;
                width[i][j] = mat[i][j] ? (1 + (j < n-1 ? width[i][j+1] : 0)) : 0;
            }
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += mat[i][j];
                dp[i][j] = sum + (i > 0 ? dp[i-1][j] : 0);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int he = height[i][j], wi= width[i][j];
                for (int h = 1; h <= he; ++h) {
                    bool matched = true;
                    for (int w = 1; w <= wi && matched; ++w) {
                        int ones = dp[i+h-1][j+w-1] + (i > 0 && j > 0 ? dp[i-1][j-1] : 0);
                        ones -= (i > 0 ? dp[i-1][j+w-1] : 0) + (j > 0 ? dp[i+h-1][j-1] : 0);
                        if ((matched = (ones == h*w)))
                            ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;

    // Output: 13
    mat = {{1,0,1},
           {1,1,0},
           {1,1,0}};
    cout << sol.numSubmat(mat) << endl;

    // Output: 24
    mat = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    cout << sol.numSubmat(mat) << endl;

    return 0;
}
