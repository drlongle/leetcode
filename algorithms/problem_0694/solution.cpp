/*
694. Number of Distinct Islands
Medium

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected
4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another
if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.

Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
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

    set<vector<pair<int, int>>> cnt;

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        cnt.clear();
        vector<vector<int>> offsets{{-1,0},{1,0},{0,-1},{0,1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> curr;
                    queue<pair<int, int>> q;
                    int minx = INT_MAX, miny = INT_MAX;
                    q.emplace(i, j);
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        curr.emplace_back(x, y);
                        minx = min(x, minx);
                        miny = min(y, miny);
                        q.pop();
                        for (auto& offset: offsets) {
                            int nx = x + offset[0], ny = y + offset[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]) {
                                q.emplace(nx, ny);
                                grid[nx][ny] = 0;
                            }
                        }
                    }
                    for (auto& p: curr) {
                        p.first -= minx, p.second -= miny;
                    }
                    sort(begin(curr), end(curr));
                    cnt.emplace(move(curr));
                }
            }
        }

        return cnt.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 1
    grid = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,0,1,1}, {0,0,0,1,1}};
    cout << sol.numDistinctIslands(grid) << endl;

    // Output: 3
    grid = {{1,1,0,1,1}, {1,0,0,0,0}, {0,0,0,0,1}, {1,1,0,1,1}};
    cout << sol.numDistinctIslands(grid) << endl;

    return 0;
}
