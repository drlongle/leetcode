/*
1905. Count Sub Islands
Medium

You are given two m x n binary matrices grid1 and grid2 containing only 0's
(representing water) and 1's (representing land). An island is a group of 1's
connected 4-directionally (horizontal or vertical). Any cells outside of the
grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1
that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

Example 1:
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]] Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on
the right is grid2. The 1s colored red in grid2 are those considered to be part
of a sub-island. There are three sub-islands.

Example 2:
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]] Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on
the right is grid2. The 1s colored red in grid2 are those considered to be part
of a sub-island. There are two sub-islands.

Constraints:
m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int res = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid1[i][j] && grid2[i][j]) {
                    grid2[i][j] = 0;
                    bool valid = true;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        for (auto &offset : offsets) {
                            auto nx = x + offset[0];
                            auto ny = y + offset[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                                grid2[nx][ny]) {
                                grid2[nx][ny] = 0;
                                q.emplace(nx, ny);
                                if (!grid1[nx][ny])
                                    valid = false;
                            }
                        }
                        q.pop();
                    }
                    res += valid;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1, grid2;

    // Exepected: 3
    grid1 = {{1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 0, 0, 0, 0},
             {1, 1, 0, 1, 1}};
    grid2 = {{1, 1, 1, 0, 0},
             {0, 0, 1, 1, 1},
             {0, 1, 0, 0, 0},
             {1, 0, 1, 1, 0},
             {0, 1, 0, 1, 0}};
    cout << sol.countSubIslands(grid1, grid2) << endl;

    // Exepected: 2
    grid1 = {{1, 0, 1, 0, 1},
             {1, 1, 1, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1},
             {1, 0, 1, 0, 1}};
    grid2 = {{0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1},
             {0, 1, 0, 1, 0},
             {0, 1, 0, 1, 0},
             {1, 0, 0, 0, 1}};
    cout << sol.countSubIslands(grid1, grid2) << endl;

    // Exepected: 0
    grid1 = {{1, 1, 1, 1, 0, 0}, {1, 1, 0, 1, 0, 0}, {1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0}, {1, 0, 1, 0, 1, 0},
             {0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 0},
             {1, 1, 1, 1, 1, 0}};
    grid2 = {{1, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}, {1, 1, 1, 1, 1, 1},
             {0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 1},
             {1, 1, 0, 1, 1, 1}, {1, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1},
             {1, 0, 0, 1, 0, 0}};
    cout << sol.countSubIslands(grid1, grid2) << endl;

    return 0;
}
