/*
1878. Get Biggest Three Rhombus Sums in a Grid
Medium

You are given an m x n integer matrix grid.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid. The rhombus must
have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image
of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:

Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three
distinct values, return all of them.

Example 1:
Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211

Example 2:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)

Example 3:
Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 10^5
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
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int, greater<int>> nums;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = grid[i][j];
                nums.insert(sum);
                int x = i+1, ly = j-1, hy = j+1, maxx = m-2;
                while (x <= maxx && ly >= 0 && hy < n) {
                    sum += grid[x][ly] + grid[x][hy];
                    int y1 = ly, y2 = hy, x1 = x, t = sum;
                    while (y1 != y2) {
                        ++y1, ++x1, --y2;
                        t += grid[x1][y1];
                        if (y1 != y2)
                            t += grid[x1][y2];
                    }
                    nums.insert(t);
                    ++x, --ly, ++hy, --maxx;
                }
            }
        }

        vector<int> r;
        for (auto it = nums.begin(); it != nums.end() && r.size() < 3; ++it)
            r.push_back(*it);
        return r;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    vector<int> res;

    // Output: {228,216,211}
    grid = {{3,4,5,1,3},
            {3,3,4,2,3},
            {20,30,200,40,10},
            {1,5,5,4,1},
            {4,3,2,2,5}};
    res = sol.getBiggestThree(grid);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {20,9,8}
    grid = {{1,2,3},
            {4,5,6},
            {7,8,9}};
    res = sol.getBiggestThree(grid);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {7}
    grid = {{7,7,7}};
    res = sol.getBiggestThree(grid);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
