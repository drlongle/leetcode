/*
1559. Detect Cycles in 2D Grid
Hard

Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting
of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell,
you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right),
if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle
(1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

Example 1:
Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:
Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:
Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false

Constraints:
m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid consists only of lowercase English letters.
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
    int m, n;
    vector<vector<bool>> visited;

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        vector<vector<int>> offsets{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<tuple<int, int, int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    char ch = grid[i][j];
                    q.emplace(i, j, -1, -1);
                    while (!q.empty()) {
                        auto& [cx, cy, px, py] = q.front();
                        visited[cx][cy] = true;

                        for (auto& offset: offsets) {
                            int nx = cx + offset[0], ny = cy + offset[1];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n || ch != grid[nx][ny] ||
                                (px == nx && py == ny))
                                continue;
                            if (visited[nx][ny])
                                return true;
                            q.emplace(nx, ny, cx, cy);
                        }
                        q.pop();
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid;

    // Output: true
    grid = {{'a','a'},{'a','a'}};
    cout << boolalpha << sol.containsCycle(grid) << endl;

    // Output: true
    grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    cout << boolalpha << sol.containsCycle(grid) << endl;

    // Output: false
    grid = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    cout << boolalpha << sol.containsCycle(grid) << endl;

    // Output: false
    grid = {{'b','a','c'},{'c','a','c'},{'d','d','c'},{'b','c','c'}};
    cout << boolalpha << sol.containsCycle(grid) << endl;

    return 0;
}
