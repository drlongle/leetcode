/*
498. Diagonal Traverse
Medium

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal
order as shown in the below image.

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Note:
The total number of elements of the given matrix will not exceed 10,000.
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
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (!m)
            return res;
        int n = matrix[0].size();
        if (!n)
            return res;
        for (int i = 0; i <= m+n; ++i) {
            if (i % 2 == 0) {
                for (int x = i; x >= 0; --x) {
                    int y = i - x;
                    if (x < m && y >= 0 && y < n)
                        res.push_back(matrix[x][y]);
                }
            } else {
                for (int x = 0; x <= i; ++x) {
                    int y = i - x;
                    if (x < m && y >= 0 && y < n)
                        res.push_back(matrix[x][y]);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    vector<int> res;

    matrix = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    res = sol.findDiagonalOrder(matrix);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
