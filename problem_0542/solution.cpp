/*
542. 01 Matrix
Medium

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Example 2:
Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<tuple<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    result[i][j] = 0;
                }
            }
        }
        vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0,-1}, {0,1}};
        while (!q.empty()) {
            const auto [i, j] = q.front();
            q.pop();
            for (const auto& offset: offsets) {
                int ni = i + offset[0], nj = j + offset[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && result[ni][nj] < 0) {
                    result[ni][nj] = 1 + result[i][j];
                    q.emplace(ni, nj);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix, result;

    // Output: {{0,0,0}, {0,1,0}, {0,0,0}}
    matrix = {{0,0,0}, {0,1,0}, {0,0,0}};

    result = sol.updateMatrix(matrix);
    for (auto& row: result) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }


    // Output: {{0,0,0}, {0,1,0}, {1,2,1}}
    matrix = {{0,0,0}, {0,1,0}, {1,1,1}};
    result = sol.updateMatrix(matrix);
    for (auto& row: result) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
