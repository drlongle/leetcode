/*
827. Making A Large Island
Hard

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
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
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), id = 2, res = 0;
        vector<vector<int>> offsets {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_map<int, int> size;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    grid[i][j] = id;
                    int cnt = 0;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        ++cnt;
                        for (auto& offset: offsets) {
                            int nx = x + offset[0], ny = y + offset[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                                grid[nx][ny] = id;
                                q.emplace(nx, ny);
                            }
                        }
                    }
                    size[id++] = cnt;
                    res = max(res, cnt);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    unordered_set<int> islands;
                    for (auto& offset: offsets) {
                        int nx = i + offset[0], ny = j + offset[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            islands.emplace(grid[nx][ny]);
                        }
                    }
                    int cnt = 1;
                    for (auto id: islands)
                        cnt += size[id];
                    res = max(res, cnt);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 3
    grid = {{1,0},{0,1}};
    cout << sol.largestIsland(grid) << endl;

    // Output: 4
    grid = {{1,1},{1,0}};
    cout << sol.largestIsland(grid) << endl;

    // Output: 4
    grid = {{1,1},{1,1}};
    cout << sol.largestIsland(grid) << endl;

    return 0;
}
