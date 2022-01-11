/*
490. The Maze
Medium

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go
through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall.
When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol]
and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination,
otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

Example 1:
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through
the destination but you cannot stop there.

Example 3:
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false

Constraints:
m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow <= m
0 <= startcol, destinationcol <= n
Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.
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

    vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;
    int m, n;

    bool possible(vector<vector<int>>& maze, int x, int y, int dir) {
        int nx = x + offsets[dir][0], ny = y + offsets[dir][1];
        return nx >= 0 && nx < m && ny >= 0 && ny < n && !maze[nx][ny];
    }

    int hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        m = maze.size(), n = maze[0].size();
        visited.resize(m, vector<int>(n, 0));
        queue<tuple<int, int, int>> q; // x, y, direction
        int x = start[0], y = start[1], dir, nx, ny;
        for (int i = 0; i < 4; ++i) {
            if (possible(maze, x, y, i)) {
                q.emplace(x, y, i);
                visited[x][y] |= (1 << i);
            }
        }

        while (q.size()) {
            auto tup = q.front();
            x = get<0>(tup), y = get<1>(tup), dir = get<2>(tup);
            q.pop();
            if (possible(maze, x, y, dir)) {
                nx = x + offsets[dir][0], ny = y + offsets[dir][1];
                if ((visited[nx][ny] & (1 << dir)) == 0) {
                    q.emplace(nx, ny, dir);
                    visited[nx][ny] |= (1 << dir);
                }
            } else {
                if (x == dest[0] && y == dest[1]) {
                    return true;
                }

                for (int i = 0; i < 4; ++i) {
                    if (i != dir && possible(maze, x, y, i)) {
                        nx = x + offsets[i][0], ny = y + offsets[i][1];
                        if ((visited[nx][ny] & (1 << i)) == 0) {
                            visited[nx][ny] |= (1 << i);
                            q.emplace(nx, ny, i);
                        }
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}
