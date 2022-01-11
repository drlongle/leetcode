/*
999. Available Captures for Rook
Difficulty: Easy

On an 8 x 8 chessboard, there is one white rook. There also may be empty
squares, white bishops, and black pawns.  These are given as characters
'R', '.', 'B', and 'p' respectively. Uppercase characters represent
white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal
directions (north, east, west, and south), then moves in that direction
until it chooses to stop, reaches the edge of the board, or captures an
opposite colored pawn by moving to the same square it occupies.  Also,
rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int capture(vector<vector<char>>& board, int i, int j, array<int, 2>& offset) {
        while (true) {
            i += offset[0];
            j += offset[1];
            if (i < 0 || i >= rows || j < 0 || j >= columns)
                break;
            if (board[i][j] == 'p')
                return 1;
            if (board[i][j] != '.')
                return 0;
        }
        return 0;
    }

    int rows, columns;

    int numRookCaptures(vector<vector<char>>& board) {
        rows = board.size();
        columns = rows > 0 ? board[0].size() : 0;

        array<array<int, 2>, 4> offsets{1, 0,-1, 0,0,1,0,-1};
        int count = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == 'R') {
                    for (auto& offset: offsets)
                        count += capture(board, i, j, offset);
                }
            }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board;

    vector<string> board_str;

    // Expected: 0
    board_str = {"........",".ppppp..",".ppBpp..",".pBRBp..",".ppBpp..",".ppppp..","........","........"};

    for (auto& str: board_str) {
        board.emplace_back(vector<char>());
        for (auto& ch: str)
            board.back().emplace_back(ch);
    }

    cout << "Result: " << sol.numRookCaptures(board) << endl;

    return 0;
}
