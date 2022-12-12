/*
1926. Nearest Exit from Entrance in Maze
Medium

You are given an m x n matrix maze (0-indexed) with empty cells (represented as
'.') and walls (represented as '+'). You are also given the entrance of the
maze, where entrance = [entrancerow, entrancecol] denotes the row and column of
the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step
into a cell with a wall, and you cannot step outside the maze. Your goal is to
find the nearest exit from the entrance. An exit is defined as an empty cell
that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest
exit, or -1 if no such path exists.

Example 1:
Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance
= [1,2] Output: 1 Explanation: There are 3 exits in this maze at [1,0], [0,2],
and [2,3]. Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

Example 2:
Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

Example 3:
Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.

Constraints:
maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.
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
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int rows = maze.size(), cols = maze[0].size();
        queue<tuple<int, int, int>> q;
        q.emplace(entrance[0], entrance[1], 0);
        vector<vector<int>> offsets{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while (!q.empty()) {
            auto e = q.front();
            int r = get<0>(e), c = get<1>(e), cur = get<2>(e);
            if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) &&
                (r != entrance[0] || c != entrance[1]))
                return cur;
            for (auto &offset : offsets) {
                int nr = r + offset[0], nc = c + offset[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    maze[nr][nc] == '.') {
                    maze[nr][nc] = '+';
                    q.emplace(nr, nc, cur + 1);
                }
            }
            q.pop();
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> maze;
    vector<int> entrance;

    // Output: 1
    maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}},
    entrance = {1, 2};
    std::cout << sol.nearestExit(maze, entrance) << endl;

    // Output: 2
    maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}},
    entrance = {1, 0};
    cout << sol.nearestExit(maze, entrance) << endl;
    ;

    // Output: -1
    maze = {{'.', '+'}}, entrance = {0, 0};
    cout << sol.nearestExit(maze, entrance) << endl;
    ;

    return 0;
}
