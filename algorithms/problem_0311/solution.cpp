/*
311. Sparse Matrix Multiplication
Medium

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:
Input:
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:
     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

Constraints:
1 <= A.length, B.length <= 100
1 <= A[i].length, B[i].length <= 100
-100 <= A[i][j], B[i][j] <= 100
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B[0].size(), k = A[0].size();
        vector<unordered_set<int>> a(m), b(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                if (A[i][j])
                    a[i].emplace(j);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (B[j][i])
                    b[i].emplace(j);
            }
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto x: a[i]) {
                    auto it = b[j].find(x);
                    if (it != b[j].end()) {
                        res[i][j] += A[i][x] * B[*it][j];
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
