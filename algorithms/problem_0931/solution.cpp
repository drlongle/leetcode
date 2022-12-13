/*
931. Minimum Falling Path Sum
Medium

Given an n x n array of integers matrix, return the minimum sum of any falling
path through matrix.

A falling path starts at any element in the first row and chooses the element in
the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col -
1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<vector<int>> dp;
    vector<vector<bool>> valid;
    int n;

    int get(vector<vector<int>> &matrix, int i, int j) {
        if (i == n - 1)
            return matrix[i][j];
        int &res = dp[i][j];
        if (valid[i][j])
            return res;

        res = get(matrix, i + 1, j);
        if (j > 0)
            res = min(res, get(matrix, i + 1, j - 1));
        if (j + 1 < n)
            res = min(res, get(matrix, i + 1, j + 1));
        res += matrix[i][j];
        dp[i][j] = res;
        valid[i][j] = true;

        return res;
    }

    int minFallingPathSum(vector<vector<int>> &matrix) {
        n = matrix.size();
        dp = vector<vector<int>>(n, vector<int>(n));
        valid = vector<vector<bool>>(n, vector<bool>(n, false));
        int res = INT_MAX;
        for (int j = 0; j < n; ++j)
            res = min(res, get(matrix, 0, j));
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << sol.minFallingPathSum(matrix) << endl;

    matrix = {{-19, 57}, {-40, -5}};
    cout << sol.minFallingPathSum(matrix) << endl;

    return 0;
}
