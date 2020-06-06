/*
794. Valid Tic-Tac-Toe State
Medium

A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true

Note:
board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    int count(vector<string> board, char ch) {
        int cnt = 0;
        for (auto& line: board)
            cnt += std::count(begin(line), end(line), ch);
        return cnt;
    }

    pair<int, bool> win(vector<string> board, char ch) {
        int rows = 0;
        for (auto& line: board) {
            rows += std::count(begin(line), end(line), ch) == 3;
        }
        if (rows > 1)
            return {0, false};
        
        int cols = 0;
        for (int i = 0; i< 3; ++i) {
            cols += board[0][i] == ch && board[1][i] == ch && board[2][i] == ch;
        }
        if (cols > 1)
            return {0, false};
        
        int diag1 = board[0][0] == ch && board[1][1] == ch && board[2][2] == ch;
        int diag2 = board[2][0] == ch && board[1][1] == ch && board[0][2] == ch;

        if (diag1 || diag2) {
            if (rows > 1 && (board[1][0] != ch || board[1][1] != ch || board[1][2] != ch))
                return {0, false};
            if (cols > 1 && (board[0][1] != ch || board[1][1] != ch || board[2][1] != ch))
                return {0, false};
        }
        
        return {rows + cols + diag1 + diag2, true};
    }
    
    bool validTicTacToe(vector<string>& board) {
        int xc = count(board, 'X');
        int oc = count(board, 'O');
        if (oc > xc || xc > oc + 1)
            return false;
        auto [xwin, xvalid] = win(board, 'X');
        auto [owin, ovalid] = win(board, 'O');
        if (!xvalid || !ovalid || (xwin && owin) || (xwin && xc == oc) || (owin && xc > oc))
            return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> board;

    // Output: false
    board = {"O  ", "   ", "   "};
    cout << boolalpha << sol.validTicTacToe(board) << endl;

    // Output: false
    board = {"XOX", " X ", "   "};
    cout << boolalpha << sol.validTicTacToe(board) << endl;
    
    // Output: false
    board = {"XXX", "   ", "OOO"};
    cout << boolalpha << sol.validTicTacToe(board) << endl;
    
    // Output: true
    board = {"XOX", "O O", "XOX"};
    cout << boolalpha << sol.validTicTacToe(board) << endl;

    // true
    board = {"XXX","OOX","OOX"};
    cout << boolalpha << sol.validTicTacToe(board) << endl;

    // false
    board = {"XXX","XOO","OO "};
    cout << boolalpha << sol.validTicTacToe(board) << endl;

    // false
    board = {"OXX","XOX","OXO"};
    cout << boolalpha << sol.validTicTacToe(board) << endl;
    
    return 0;
}
