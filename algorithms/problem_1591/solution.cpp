/*
1591. Strange Printer II
Hard

There is a strange printer with the following two special requirements:

On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up
the existing colors in the rectangle. Once the printer has used a color for the above operation, the same color cannot
be used again. You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position
(row, col) of the grid.

Return true if it is possible to print the matrix targetGrid, otherwise, return false.

Example 1:
Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
Output: true

Example 2:
Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
Output: true

Example 3:
Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
Output: false
Explanation: It is impossible to form targetGrid because it is not allowed to print the
same color in different turns.

Example 4:
Input: targetGrid = [[1,1,1],[3,1,3]]
Output: false

Constraints:
m == targetGrid.length
n == targetGrid[i].length
1 <= m, n <= 60
1 <= targetGrid[row][col] <= 60
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

struct Color {
    int left, right, low, high;
    bool full;
    Color() : left(numeric_limits<int>::max()), right(numeric_limits<int>::min()),
        low(numeric_limits<int>::max()), high(numeric_limits<int>::min()), full(false)
    {}
    set<pair<int, int>> pos;
    bool contain(const pair<int, int>& p) {
        return low <= p.first && p.first <= high && left <= p.second && p.second <= right;
    }
};
class Solution {
public:
    unordered_map<int, Color> colors;

    void check(Color& color) {
        color.full = (color.pos.size() == (color.high - color.low + 1) * (color.right - color.left + 1));
    }

    bool isPrintable(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = grid[i][j];
                auto [it, ignored] = colors.emplace(c, Color());
                auto& color = it->second;
                color.low = min(i, color.low);
                color.high = max(i, color.high);
                color.left = min(j, color.left);
                color.right = max(j, color.right);
                color.pos.emplace(i, j);
            }
        }

        bool loop = true;
        while (loop) {
            loop = false;
            for (auto& [c, color]: colors) {
                if (color.full)
                    continue;
                check(color);
                if (color.full) {
                    for (auto& p: color.pos) {
                        for (auto& [c2, color2]: colors) {
                            if (!color2.full && color2.contain(p)) {
                                color2.pos.emplace(p);
                            }
                        }
                    }
                    loop = true;
                    break;
                }
            }
        }

        size_t cnt = count_if(begin(colors), end(colors), [] (auto& p) {return p.second.full;});
        return cnt == colors.size();
    }
};

int main() {
    vector<vector<int>> targetGrid;

    // Output: true
    {
        Solution sol;
        targetGrid = {{1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}};
        cout << boolalpha << sol.isPrintable(targetGrid) << endl;
    }

    // Output: true
    {
        Solution sol;
        targetGrid = {{1,1,1,1},{1,1,3,3},{1,1,3,4},{5,5,1,4}};
        cout << boolalpha << sol.isPrintable(targetGrid) << endl;
    }

    // Output: false
    targetGrid = {
            {1,2,1},
            {2,1,2},
            {1,2,1}};
    {
        Solution sol;
        cout << boolalpha << sol.isPrintable(targetGrid) << endl;
    }

    // Output: false
    targetGrid = {
            {1,1,1},
            {3,1,3}};
    {
        Solution sol;
        cout << boolalpha << sol.isPrintable(targetGrid) << endl;
    }

    // Output: true
    targetGrid = {
            {6,2,2,5},
            {2,2,2,5},
            {2,2,2,5},
            {4,3,3,4}};
    {
        Solution sol;
        cout << boolalpha << sol.isPrintable(targetGrid) << endl;
    }

    return 0;
}
