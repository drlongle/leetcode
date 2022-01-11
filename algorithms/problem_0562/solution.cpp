/*
562. Longest Line of Consecutive One in Matrix
Medium

Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.

Example 1:
Input: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
Output: 3

Example 2:
Input: mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
Output: 4

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int res = 0, m = M.size();
        if (!m) return 0;
        int n = M[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!M[i][j])
                    continue;
                for(int k = j, run = 0; (j == 0 || !M[i][j-1]) && k < n && M[i][k]; ++k) {
                    res = max(res, ++run);
                }
                for(int k=i, run = 0; (i == 0 || !M[i-1][j]) && k < m && M[k][j]; ++k) {
                    res = max(res,++run);
                }
                for (int k = i, l = j, run = 0; (i==0 || j==0 || !M[i-1][j-1]) && k < m && l < n && M[k][l]; ++k, ++l)
                    res=max(res, ++run);
                for(int k = i, l = j, run = 0; (i == 0 || j == n-1 || !M[i-1][j+1]) && k < m && l >= 0 && M[k][l]; ++k,--l)
                    res=max(res,++run);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
