/*

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
    int m, n;
    vector<vector<int>> visited;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int res = 1;
        for (auto& offset: offsets) {
            int ni = i + offset[0], nj = j + offset[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && grid[ni][nj]) {
                visited[ni][nj] = 1;
                res += dfs(grid, ni, nj);
            }
        }
        return res;
    }

    vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        visited.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !visited[i][j]) {
                    visited[i][j] = 1;
                    res = max(res, dfs(grid, i, j));
                }

            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;


    grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout << sol.maxAreaOfIsland(grid) << endl;

    return 0;
}
