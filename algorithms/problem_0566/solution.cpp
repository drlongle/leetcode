/*
566. Reshape the Matrix
Easy

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one
with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the row number and column number
of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same
row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix;
Otherwise, output the original matrix.

Example 1:
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Example 2:
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300
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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m * n; ++i) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;
    int r, c;

    // Output: {{1,2,3,4}}
    mat = {{1,2},{3,4}}, r = 1, c = 4;
    mat = sol.matrixReshape(mat, r, c);
    for (auto& row: mat) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    //Output: {{1,2},{3,4}}
    mat = {{1,2},{3,4}}, r = 2, c = 4;
    mat = sol.matrixReshape(mat, r, c);
    for (auto& row: mat) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
