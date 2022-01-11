/*
1631. Path With Minimum Effort
Medium

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell,
(0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can
move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells,
which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Constraints:
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 10^6
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

struct Entry {
    Entry(int x_, int y_, int d): x(x_), y(y_), diff(d) {}
    int x, y, diff;
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, numeric_limits<int>::max()));
        queue<Entry> q;
        vector<vector<int>> offsets {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.emplace(0, 0, 0);
        visited[0][0] = 0;
        while (q.size()) {
            auto& e = q.front();
            for (auto& offset: offsets) {
                int x = e.x + offset[0], y = e.y + offset[1];
                if (x >= 0 && x < rows && y >= 0 && y < cols && (e.x != rows-1 || e.y != cols-1)) {
                    int diff = max(e.diff, abs(heights[e.x][e.y] - heights[x][y]));
                    if (diff < visited[x][y]) {
                        q.emplace(x, y, diff);
                        visited[x][y] = diff;
                    }
                }
            }
            q.pop();
        }

        return visited[rows-1][cols-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heights;

    // Output: 2
    heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << sol.minimumEffortPath(heights) << endl;

    // Output: 1
    heights = {{1,2,3},{3,8,4},{5,3,5}};
    cout << sol.minimumEffortPath(heights) << endl;

    // Output: 0
    heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << sol.minimumEffortPath(heights) << endl;

    return 0;
}
