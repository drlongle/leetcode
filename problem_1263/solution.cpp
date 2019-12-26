/*
1263. Minimum Moves to Move a Box to Their Target Location
Hard

Storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.

The game is represented by a grid of size n*m, where each element is a wall, floor, or a box.

Your task is move the box 'B' to the target position 'T' under the following rules:

Player is represented by character 'S' and can move up, down, left, right in the grid if it is a floor (empy cell).
Floor is represented by character '.' that means free cell to walk.
Wall is represented by character '#' that means obstacle  (impossible to walk there). 
There is only one box 'B' and one target cell 'T' in the grid.
The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
The player cannot walk through the box.
Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.

Example 1:
Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#",".","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 3
Explanation: We return only the number of times the box is pushed.
Example 2:

Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#","#","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: -1
Example 3:

Input: grid = [["#","#","#","#","#","#"],
               ["#","T",".",".","#","#"],
               ["#",".","#","B",".","#"],
               ["#",".",".",".",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 5
Explanation:  push the box down, left, left, up and up.
Example 4:

Input: grid = [["#","#","#","#","#","#","#"],
               ["#","S","#",".","B","T","#"],
               ["#","#","#","#","#","#","#"]]
Output: -1

Constraints:

1 <= grid.length <= 20
1 <= grid[i].length <= 20
grid contains only characters '.', '#',  'S' , 'T', or 'B'.
There is only one character 'S', 'B' and 'T' in the grid.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    using Array = array<int, 2>;
    static constexpr array<Array, 4> offsets = {Array{0, 1}, Array{0, -1}, Array{-1, 0}, Array{1, 0}};

    inline bool valid_position(const vector<vector<char>>& grid, const pair<int, int>& pos) {
        return (pos.first >= 0 && pos.first < rows && pos.second >= 0 && pos.second < cols
                && (grid[pos.first][pos.second] == '.' || grid[pos.first][pos.second] == 'T'));
    }

    inline bool find_path(const vector<vector<char>>& grid, const pair<int, int>& src, const pair<int, int>& dst) {
        vector<pair<int, int>> closer, detour;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        closer.emplace_back(src);
        while (closer.size() || detour.size()) {
            if (closer.empty())
                swap(closer, detour);
            auto pos = closer.back();
            visited[pos.first][pos.second] = 1;
            closer.pop_back();
            if (pos == dst)
                return true;
            for (auto& offset: offsets) {
                pair<int, int> npos{pos.first + offset[0], pos.second + offset[1]};
                if (valid_position(grid, npos) && visited[npos.first][npos.second] == 0) {
                    if (dot({offset[0], offset[1]}, {src.first - dst.first, src.second - dst.second}) > 0)
                        closer.emplace_back(npos);
                    else
                        detour.emplace_back(npos);
                }
            }
        }
        
        return false;
    }
    
    struct Move {
        Move(int c, pair<int, int>& b, pair<int, int>& p): count(c), box(b), player(p) {}
        int count;
        pair<int, int> box, player;
    };

    struct HashOp {
        size_t operator()(const pair<int, int>& p) const {
            return p.first * 1001 + p.second;
        }
    };

    inline int dot(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * b.first + a.second * b.second;
    }
    
    int minPushBox(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        pair<int, int> box, target, player;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                switch (grid[i][j]) {
                    case 'B':
                        box = make_pair(i, j);
                        break;
                    case 'S':
                        player = make_pair(i, j);
                        break;
                    case 'T':
                        target = make_pair(i, j);
                        break;
                }
            }

        unordered_set<pair<int, int>, HashOp> moves;
        vector<Move> closer, detour;
        closer.emplace_back(0, box, player);
        moves.emplace(make_pair<int, int>(box.first*cols + box.second, player.first*cols+ player.second));
        while (closer.size() || detour.size()) {
            if (closer.empty())
                swap(closer, detour);
            auto m = closer.back();
            closer.pop_back();
            if (m.box == target)
                return m.count;
            grid[m.box.first][m.box.second] = 'B';
            grid[m.player.first][m.player.second] = 'P';

            for (auto& offset: offsets) {
                pair<int, int> box_pos{m.box.first + offset[0], m.box.second + offset[1]};
                pair<int, int> player_pos{m.box.first - offset[0], m.box.second - offset[1]};

                if (valid_position(grid, box_pos)
                    && valid_position(grid, player_pos)
                    && moves.count({box_pos.first*cols + box_pos.second,
                                    player_pos.first * cols + player_pos.second}) == 0
                    && find_path(grid, m.player, player_pos)) {
                    if (dot({-offset[0], -offset[1]},
                            {m.box.first - target.first, m.box.second - target.second}) > 0)
                        closer.emplace_back(m.count+1, box_pos, player_pos);
                    else
                        detour.emplace_back(m.count+1, box_pos, player_pos);                        
                    moves.emplace(make_pair<int, int>(
                                      box_pos.first * cols + box_pos.second,
                                      player_pos.first * cols + player_pos.second));
                }
            }

            grid[m.box.first][m.box.second] = '.';
            if (player != target)
                grid[m.player.first][m.player.second] = '.';
            else
                grid[target.first][target.second] = 'T';
        }

        return -1;
    }
    int rows, cols;
};

int main() {
    Solution sol;
    vector<vector<char>> grid;

    // Output: 3
    grid = {vector<char>{'#','#','#','#','#','#'},
            vector<char>{'#','T','#','#','#','#'},
            vector<char>{'#','.','.','B','.','#'},
            vector<char>{'#','.','#','#','.','#'},
            vector<char>{'#','.','.','.','S','#'},
            vector<char>{'#','#','#','#','#','#'}};


    // Output: -1
    /*
    grid = {vector<char>{'#','#','#','#','#','#'},
            vector<char>{'#','T','#','#','#','#'},
            vector<char>{'#','.','.','B','.','#'},
            vector<char>{'#','#','#','#','.','#'},
            vector<char>{'#','.','.','.','S','#'},
            vector<char>{'#','#','#','#','#','#'}};
    */
    
    // Output: 5
    /*
    grid = {vector<char>{'#','#','#','#','#','#'},
            vector<char>{'#','T','.','.','#','#'},
            vector<char>{'#','.','#','B','.','#'},
            vector<char>{'#','.','.','.','.','#'},
            vector<char>{'#','.','.','.','S','#'},
            vector<char>{'#','#','#','#','#','#'}};
    */
    
    // Output: -1
    /*
    grid = {vector<char>{'#','#','#','#','#','#','#'},
            vector<char>{'#','S','#','.','B','T','#'},
            vector<char>{'#','#','#','#','#','#','#'}};
    */

    // Output: 8
    /*
    grid = {vector<char>{'#','.','.','#','T','#','#','#','#'},
            vector<char>{'#','.','.','#','.','#','.','.','#'},
            vector<char>{'#','.','.','#','.','#','B','.','#'},
            vector<char>{'#','.','.','.','.','.','.','.','#'},
            vector<char>{'#','.','.','.','.','#','.','S','#'},
            vector<char>{'#','.','.','#','.','#','#','#','#'}};
    */
    
    /*
    grid = {
        vector<char>{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#'},
        vector<char>{'#','.','#','#','#','#','.','#','#','#','#','.','#','#','#','.'},
        vector<char>{'#','.','.','.','.','.','.','#','T','#','.','.','#','#','#','.'},
        vector<char>{'#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.'},
        vector<char>{'#','.','.','.','.','.','B','.','.','.','.','.','#','#','#','.'},
        vector<char>{'#','.','#','#','#','#','#','#','#','#','#','.','#','#','#','.'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        vector<char>{'#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.'},
        vector<char>{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
    */

    // Output: 29
    grid = {
        vector<char>{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#'},
        vector<char>{'#','.','.','.','#','#','.','#','#','#','#','.','#','#','#','.','#','#','T','#'},
        vector<char>{'#','.','.','.','.','.','.','#','.','#','.','.','#','#','#','.','#','#','.','#'},
        vector<char>{'#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#'},
        vector<char>{'#','.','#','.','.','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#'},
        vector<char>{'#','.','#','.','#','#','#','#','#','#','#','.','#','#','#','.','#','#','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','B','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

    // Output; 26
    grid = {
        vector<char>{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#'},
        vector<char>{'#','.','.','.','#','#','#','#','.','#','#','#','#','.','#','#','#','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','#','T','#','.','.','#','#','#','.','#'},
        vector<char>{'#','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.','#'},
        vector<char>{'#','.','#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','.','#'},
        vector<char>{'#','.','#','.','#','#','#','#','#','#','#','#','#','.','#','#','#','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','B','.','#','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','#','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
        vector<char>{'#','.','.','.','.','.','.','.','.','.','S','.','.','.','.','#','.','.','#'},
        vector<char>{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
    
    cout << "Result: " << sol.minPushBox(grid) << endl;

    return 0;
}
