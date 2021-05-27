/*
353. Design Snake Game
Medium

Design a Snake game that is played on a device with screen size height x width. Play the game online
if you are not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.

You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food
that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until
the snake eats the first piece of food.

When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that
its body occupies after moving (i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:
SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.

Example 1:
Input
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
Output
[null, 0, 0, 1, 1, 2, -1]

Explanation
SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
snakeGame.move("R"); // return 0
snakeGame.move("D"); // return 0
snakeGame.move("R"); // return 1, snake eats the first piece of food. The second piece of food appears
                     // at (0, 1).
snakeGame.move("U"); // return 1
snakeGame.move("L"); // return 2, snake eats the second food. No more food appears.
snakeGame.move("U"); // return -1, game over because snake collides with border

Constraints:
1 <= width, height <= 10^4
1 <= food.length <= 50
food[i].length == 2
0 <= ri < height
0 <= ci < width
direction.length == 1
direction is 'U', 'D', 'L', or 'R'.
At most 10^4 calls will be made to move.
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

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food):
            w(width),
            h(height),
            f(food.begin(), food.end()),
            pos{{0,0}}
    {

    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        static vector<vector<int>> offsets{{-1,0}, {1,0}, {0,-1}, {0,1}};
        int index;
        char c = direction[0];
        if (c == 'U')
            index = 0;
        else if (c == 'D')
            index = 1;
        else if (c == 'L')
            index = 2;
        else
            index = 3;

        auto np = pos[0];
        np[0] += offsets[index][0];
        np[1] += offsets[index][1];

        if (np[0] < 0 || np[0] >= h || np[1] < 0 || np[1] > =w)
            return -1;
        if (f.size() && np == f[0]) {
            pos.push_front(np);
            f.pop_front();
        } else {
            for (int i = pos.size() - 1; i > 0; --i) {
                pos[i] = pos[i-1];
                if (np == pos[i])
                    return -1;
            }
            pos[0]  = np;
        }

        return pos.size() - 1;
    }

    int h,w;
    deque<vector <int>> f;
    deque<vector<int>> pos;
};

int main() {
    Solution sol;

    return 0;
}
