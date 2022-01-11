/*
750. Number Of Corner Rectangles
Medium

Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle.
Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

Example 1:
Input: grid =
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].

Example 2:
Input: grid =
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.

Example 3:
Input: grid =
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.

Note:
The number of rows and columns of grid will each be in the range [1, 200].
Each grid[i][j] will be either 0 or 1.
The number of 1s in the grid will be at most 6000.
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
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m)
            return 0;
        int n = grid[0].size(), res = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (!grid[i][j])
                    continue;
                for (int x = 2; i + x <= m; ++x) {
                    if (!grid[i+x-1][j])
                        continue;
                    for (int y = 2; j + y <= n; ++y) {
                        res += grid[i][j+y-1] && grid[i+x-1][j+y-1];
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 1
    grid =
    {{1, 0, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1}};
    cout << sol.countCornerRectangles(grid) << endl;

    // Output: 9
    grid =
    {{1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}};
    cout << sol.countCornerRectangles(grid) << endl;

    // Output: 0
    grid = {{1, 1, 1, 1}};
    cout << sol.countCornerRectangles(grid) << endl;

    return 0;
}
