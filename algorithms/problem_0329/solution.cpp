/*
329. Longest Increasing Path in a Matrix

Difficulty:Hard
Total Accepted:57.7K
Total Submissions:153.4K

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You
may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int rows, columns;
    int explore(vector<vector<int>>& matrix, vector<vector<int>>& dp,
        int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 1;
        vector<pair<int, int>> offsets{{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto& offset: offsets) {
            int ni = i + offset.first;
            int nj = j + offset.second;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < columns &&
                matrix[ni][nj] < matrix[i][j])
                dp[i][j] = max(dp[i][j], 1 + explore(matrix, dp, ni, nj));
        }
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        rows = matrix.size(); 
        if (!rows) return 0;
        columns = matrix[0].size(); 
        if (!columns) return 0;
        vector<vector<int>> dp(rows, vector<int>(columns, -1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int temp = explore(matrix, dp, i, j);
                res = max(res, temp);
            }
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<vector<int>> matrix;

    // Expected: 4
    matrix = { {9,9,4}, {6,6,8}, {2,1,1} };

    // Expected: 4
    matrix = { {3,4,5}, {3,2,6}, {2,2,1} };

    cout << "Result: " << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}

