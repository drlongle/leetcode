/*
1072. Flip Columns For Maximum Number of Equal Rows
Medium

Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip
every cell in that column. Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

Return the maximum number of rows that have all values equal after some number of flips.

Example 1:
Input: [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

Example 2:
Input: [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.

Example 3:
Input: [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.

Note:
1 <= matrix.length <= 300
1 <= matrix[i].length <= 300
All matrix[i].length's are equal
matrix[i][j] is 0 or 1
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
    bool complement(vector<int>& a, vector<int>& b) {
        int sz = a.size(), sum = 0;
        for (int i = 0; i < sz; ++i) {
            sum += (a[i] ^ b[i]);
        }
        return sum == 0 || sum == sz;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            int match = 0;
            for (int j = 0; j < m; ++j) {
                match += complement(matrix[i], matrix[j]);
            }
            res = max(res, match);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    // 0 1
    // 1 1
    // Output: 1
    matrix = {{0,1},{1,1}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << endl;

    // 0 1
    // 1 0
    // Output: 2
    matrix = {{0,1},{1,0}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << endl;

    // 0 0 0
    // 0 0 1
    // 1 1 0
    // Output: 2
    matrix = {{0,0,0},{0,0,1},{1,1,0}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << endl;

    // 0 0 0
    // 0 0 1
    // 1 1 0
    // 1 0 0
    // Output: 2
    matrix = {{0,0,0},{0,0,1},{1,1,0},{1,0,0}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << endl;

    return 0;
}
