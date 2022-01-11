/*
1074. Number of Submatrices That Sum to Target
Hard

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate
that is different: for example, if x1 != x1'.

Example 1:
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Example 3:
Input: matrix = [[904]], target = 0
Output: 0

Constraints:
1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + matrix[i][j];
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l <= k; ++l) {
                        int sum = dp[i+1][k+1] - dp[i+1][l] - dp[j][k+1] + dp[j][l];
                        res += (sum == target);
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    int target;

    // Output: 4
    matrix = {{0,1,0},{1,1,1},{0,1,0}}, target = 0;
    cout << sol.numSubmatrixSumTarget(matrix, target) << endl;

    // Output: 5
    matrix = {{1,-1},{-1,1}}, target = 0;
    cout << sol.numSubmatrixSumTarget(matrix, target) << endl;

    // Output: 0
    matrix = {{904}}, target = 0;
    cout << sol.numSubmatrixSumTarget(matrix, target) << endl;

    // Output: 28
    matrix = {{0,0,0,1,1},
              {1,1,1,0,1},
              {1,1,1,1,0},
              {0,0,0,1,0},
              {0,0,0,1,1}};
    target = 0;
    cout << sol.numSubmatrixSumTarget(matrix, target) << endl;

    return 0;
}
