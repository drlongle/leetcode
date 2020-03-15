/*
1380. Lucky Numbers in a Matrix
Easy

Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

Example 1:
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column

Example 2:
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:
Input: matrix = [[7,8],[1,2]]
Output: [7]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> minrows(m, numeric_limits<int>::max()), maxcols(n, numeric_limits<int>::min());
        for (int i = 0; i < m; ++i) {
            auto max_it = min_element(matrix[i].begin(), matrix[i].end());
            minrows[i] = *max_it;
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                maxcols[j] = max(maxcols[j], matrix[i][j]);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int n = matrix[i][j];
                if (n == minrows[i] && n == maxcols[j])
                res.emplace_back(n);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    vector<int> res;

    // Output: {15}
    matrix = {{3,7,8},{9,11,13},{15,16,17}};
    res = sol.luckyNumbers(matrix);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {12}
    matrix = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    res = sol.luckyNumbers(matrix);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // Output: {7}
    matrix = {{7,8},{1,2}};
    res = sol.luckyNumbers(matrix);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
