/*
2257. Count Unguarded Cells in the Grid
Medium

You are given two integers m and n representing a 0-indexed m x n grid. You are
also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli]
and walls[j] = [rowj, colj] represent the positions of the ith guard and jth
wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south,
or west) starting from their position unless obstructed by a wall or another
guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

Example 1:
Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green
respectively in the above diagram. There are a total of 7 unguarded cells, so we
return 7.

Example 2:
Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.

Constraints:
1 <= m, n <= 10^5
2 <= m * n <= 10^5
1 <= guards.length, walls.length <= 5 * 10^4
2 <= guards.length + walls.length <= m * n
guards[i].length == walls[j].length == 2
0 <= rowi, rowj < m
0 <= coli, colj < n
All the positions in guards and walls are unique.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (auto &w : walls) {
            matrix[w[0]][w[1]] = 1;
        }
        for (auto &g : guards) {
            matrix[g[0]][g[1]] = 2;
        }

        for (auto &g : guards) {
            int i = g[0], j = g[1];
            for (int k = i + 1; k < m && matrix[k][j] != 1; ++k) {
                if (matrix[k][j] == -1)
                    break;
                matrix[k][j] = -1;
            }
            for (int k = i - 1; k >= 0 && matrix[k][j] != 1; --k) {
                if (matrix[k][j] == -1)
                    break;
                matrix[k][j] = -1;
            }
            for (int k = j + 1; k < n && matrix[i][k] != 1; ++k) {
                if (matrix[i][k] == -2)
                    break;
                matrix[i][k] = -2;
            }
            for (int k = j - 1; k >= 0 && matrix[i][k] != 1; --k) {
                if (matrix[i][k] == -2)
                    break;
                matrix[i][k] = -2;
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    ++res;
            }
        return res;
    }
};

int main() {
    Solution sol;
    int m, n;
    vector<vector<int>> guards, walls;

    m = 4, n = 6, guards = {{0, 0}, {1, 1}, {2, 3}},
    walls = {{0, 1}, {2, 2}, {1, 4}};
    cout << sol.countUnguarded(m, n, guards, walls) << endl;

    return 0;
}
