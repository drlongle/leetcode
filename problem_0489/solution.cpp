/*
489. Robot Room Cleaner
Hard

Given a robot cleaner in a room modeled as a grid.

Each cell in the grid can be empty or blocked.

The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made
is 90 degrees.

When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays
on the current cell.

Design an algorithm to clean the entire room using only the 4 given APIs shown below.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}

Example:
Input:
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3

Explanation:
All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.
Notes:

The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
The robot's initial position will always be in an accessible cell.
The initial direction of the robot will be facing up.
All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
Assume all four edges of the grid are all surrounded by wall.
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Robot {
public:
    vector<vector<int>> offsets{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    Robot(vector<vector<int>>& ro, int r, int c):
    room(ro),
    dir(0),
    pos{r, c}
    {
    }

    vector<vector<int>> room;
    int row, col, dir;
    pair<int, int> pos;

    bool move() {
        int x = pos.first + offsets[dir][0];
        int y = pos.second + offsets[dir][1];
        if (x >= 0 && x < room.size() && y >= 0 && y < room[0].size() && room[x][y]) {
            pos.first = x, pos.second = y;
            return true;
        }
        return false;
    }

    // Robot will stay on the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft() {
        dir = (dir + 1) % 4;
    }
    void turnRight() {
        dir = (dir + 3) % 4;
    }

    // Clean the current cell.
    void clean() {
        auto& cell = room[pos.first][pos.second];
        if (cell == 0)
            abort();
        cell = 2;
    }
};

class Wrapper {
public:
    vector<vector<int>> offsets{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int dir = 0;

    void set_robot(Robot& r) {robot = &r;}

    bool move() {
        if (!robot->move())
            return false;
        pos.first += offsets[dir][0];
        pos.second += offsets[dir][1];
        return true;
    }

    void turnLeft() {
        dir = (dir + 1) % 4;
        return robot->turnLeft();
    }

    void turnRight() {
        dir = (dir + 3) % 4;
        return robot->turnRight();
    }

    Robot* robot;
    pair<int, int> pos;
};

class Solution {
public:

    Wrapper wrapper;
    set<pair<int, int>> visited;

    void DFS() {
        wrapper.robot->clean();
        visited.emplace(wrapper.pos);
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next_pos = {wrapper.pos.first + wrapper.offsets[wrapper.dir][0],
                                       wrapper.pos.second + wrapper.offsets[wrapper.dir][1]};
            if (visited.count(next_pos) == 0 && wrapper.move()) {
                DFS();
            }
            wrapper.turnLeft();
        }

        wrapper.turnLeft(); wrapper.turnLeft();
        wrapper.move();
        wrapper.turnLeft(); wrapper.turnLeft();
    }

    void cleanRoom(Robot& robot) {
        wrapper.set_robot(robot);
        DFS();
    }
};

void test_1()
{
    vector<vector<int>> room = {
            {1,1,1,1,1,0,1,1},
            {1,1,1,1,1,0,1,1},
            {1,0,1,1,1,1,1,1},
            {0,0,0,1,0,0,0,0},
            {1,1,1,1,1,1,1,1}
    };
    int row = 1, col = 3;
    Robot robot(room, row, col);
    Solution sol;
    sol.cleanRoom(robot);
}

void test_2()
{
    vector<vector<int>> room = {{0,1,0},{1,1,1},{0,1,0}};
    int row = 0, col = 1;
    Robot robot(room, row, col);
    Solution sol;
    sol.cleanRoom(robot);
}

int main() {
    test_2();
}
