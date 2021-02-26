/*
1765. Map of Highest Peak
Medium

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to
another cell if the former is directly north, east, south, or west of the latter (i.e., their sides
are touching). Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height.
If there are multiple solutions, return any of them.

Example 1:
Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.

Example 2:
Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

Constraints:
m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto& cell = isWater[i][j];
                if (cell) {
                    q.emplace(i, j);
                    cell = 0;
                } else
                    cell = INT_MAX;
            }
        }

        vector<vector<int>> offsets {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            int h = isWater[i][j];
            int nh = h + 1;
            for (auto&offset: offsets) {
                int ni = i + offset[0], nj = j + offset[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (isWater[ni][nj] > nh) {
                        isWater[ni][nj] = nh;
                        q.emplace(ni, nj);
                    }
                }
            }
        }
        return isWater;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{0,1},{0,0}};
    matrix = sol.highestPeak(matrix);
    for (auto& row: matrix) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }


    return 0;
}
