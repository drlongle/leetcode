/*
1582. Special Positions in a Binary Matrix
Easy

Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, return the number of special positions in mat.

A position (i,j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:
Input: mat = [[1,0,0],
              [0,0,1],
              [1,0,0]]
Output: 1
Explanation: (1,2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

Example 2:
Input: mat = [[1,0,0],
              [0,1,0],
              [0,0,1]]
Output: 3
Explanation: (0,0), (1,1) and (2,2) are special positions.

Example 3:
Input: mat = [[0,0,0,1],
              [1,0,0,0],
              [0,1,1,0],
              [0,0,0,0]]
Output: 2

Example 4:
Input: mat = [[0,0,0,0,0],
              [1,0,0,0,0],
              [0,1,0,0,0],
              [0,0,1,0,0],
              [0,0,0,1,1]]
Output: 3

Constraints:
rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is 0 or 1.
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
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                rows[i] += mat[i][j];
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i)
                cols[j] += mat[i][j];
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (rows[i] != 1)
                continue;
            for (int j = 0; j < n; ++j)
                res += (cols[j] == 1 && mat[i][j] == 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;

    mat = {{1,0,0},
           {0,0,1},
           {1,0,0}};
    cout << sol.numSpecial(mat) << endl;

    return 0;
}
