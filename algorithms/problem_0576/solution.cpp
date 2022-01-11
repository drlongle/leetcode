/*
576. Out of Boundary Paths
Medium

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn].
You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out of the grid
crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball
out of the grid boundary. Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow <= m
0 <= startColumn <= n
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    using ll = long long;
    static constexpr ll MOD = 1000000007;

    unordered_map<int, ll> cache;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (!maxMove)
            return 0;
        int key = 2500 * startRow + 50 * startColumn + maxMove;
        auto it = cache.find(key);
        if (it != cache.end())
            return it->second;
        ll res = 0;
        for (auto& offset: offsets) {
            int x = startRow + offset[0], y = startColumn + offset[1];
            if (x < 0 || x >= m || y < 0 || y >= n)
                ++res;
            else
                res = (res + findPaths(m, n, maxMove - 1, x, y)) % MOD;
        }

        return cache[key] = res % MOD;
    }
};

int main() {
    Solution sol;
    int m, n, maxMove, startRow, startColumn;

    // Output: 6
    m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    cout << sol.findPaths(m, n, maxMove, startRow, startColumn) << endl;

    // Output: 12
    m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
    cout << sol.findPaths(m, n, maxMove, startRow, startColumn) << endl;

    m = 8, n = 7, maxMove = 16, startRow = 1, startColumn = 5;
    cout << sol.findPaths(m, n, maxMove, startRow, startColumn) << endl;

    return 0;
}
