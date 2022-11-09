/*
1706. Where Will the Ball Fall
Medium

You have a 2-D grid of size m x n representing a box, and you have n balls. The
box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that
can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the
bottom-right corner and is represented in the grid as 1. A board that redirects
the ball to the left spans the top-right corner to the bottom-left corner and is
represented in the grid as -1. We drop one ball at the top of each column of the
box. Each ball can get stuck in the box or fall out of the bottom. A ball gets
stuck if it hits a "V" shaped pattern between two boards or if a board redirects
the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball
falls out of at the bottom after dropping the ball from the ith column at the
top, or -1 if the ball gets stuck in the box.

Example 1:
Input: grid =
[[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2
and 3 and row 1. Ball b2 is dropped at column 2 and will get stuck on the box
between column 2 and 3 and row 0. Ball b3 is dropped at column 3 and will get
stuck on the box between column 2 and 3 and row 0. Ball b4 is dropped at column
4 and will get stuck on the box between column 2 and 3 and row 1.

Example 2:
Input: grid = [[-1]]
Output: [-1]
Explanation: The ball gets stuck against the left wall.

Example 3:
Input: grid =
[[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]] Output:
[0,1,2,3,4,-1]

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is 1 or -1.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int get(vector<vector<int>> &grid, int row, int col) {
        if (row == rows)
            return col;
        int &res = cached[row][col];
        if (res >= -1)
            return res;
        if (grid[row][col] == 1) {
            if (col == columns - 1 || grid[row][col + 1] == -1)
                res = -1;
            else
                res = get(grid, row + 1, col + 1);
        } else {
            if (col == 0 || grid[row][col - 1] == 1)
                res = -1;
            else
                res = get(grid, row + 1, col - 1);
        }
        return res;
    }

    vector<vector<int>> cached;
    int rows, columns;

    vector<int> findBall(vector<vector<int>> &grid) {
        rows = grid.size();
        columns = grid[0].size();
        cached.clear();
        cached.resize(rows, vector<int>(columns, -2));

        vector<int> res(columns);
        for (int i = 0; i < columns; ++i) {
            res[i] = get(grid, 0, i);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    vector<int> res;

    // Output: [1,-1,-1,-1,-1]
    grid = {{1, 1, 1, -1, -1},
            {1, 1, 1, -1, -1},
            {-1, -1, -1, 1, 1},
            {1, 1, 1, 1, -1},
            {-1, -1, -1, -1, -1}};
    res = sol.findBall(grid);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {-1}
    grid = {{-1}};
    res = sol.findBall(grid);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {0,1,2,3,4,-1}
    grid = {{1, 1, 1, 1, 1, 1},
            {-1, -1, -1, -1, -1, -1},
            {1, 1, 1, 1, 1, 1},
            {-1, -1, -1, -1, -1, -1}};
    res = sol.findBall(grid);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
