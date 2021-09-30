/*
782. Transform to Chessboard
Hard

You are given an n x n binary grid board. In each move, you can swap any two rows
with each other, or any two columns with each other.

Return the minimum number of moves to transform the board into a chessboard board.
If the task is impossible, return -1.

A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.

Example 1:
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation: One potential sequence of moves is shown.
The first move swaps the first and second column.
The second move swaps the second and third row.

Example 2:
Input: board = [[0,1],[1,0]]
Output: 0
Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.

Example 3:
Input: board = [[1,0],[1,0]]
Output: -1
Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.

Constraints:
n == board.length
n == board[i].length
2 <= n <= 30
board[i][j] is either 0 or 1.
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

/*
 * When we look at the rows, they should have only two patterns. The rows starting
 * with 1 should be equal. All rows starting with 0 should also be equal. The same
 * is also true for all columns. So we can reduce the matrix to just two rows and
 * count how many times we have to swap the elements in those rows.
 */

class Solution {
public:
    int n;
    int check(vector<vector<int>>& board) {
        int res = INT_MAX;
        vector<vector<int>> rows;
        for (auto& row: board) {
            int ones = 0, zeroes = 0;
            for (int r: row) {
                ones += r == 1;
                zeroes += r == 0;
            }
            if (abs(ones - zeroes) > 1)
                return INT_MAX;
            bool dup = false;
            for (auto& r: rows) {
                if (r == row) {
                    dup = true;
                    break;
                }
            }
            if (!dup)
                rows.push_back(row);
            if (rows.size() > 2)
                return INT_MAX;
        }
        if (rows.size() == 1)
            return INT_MAX;

        vector<int> values;
        int ones = 0, zeroes = 0;
        for (int r: rows[0]) {
            ones += r == 1;
            zeroes += r == 0;
        }
        if (ones > zeroes)
            values = {1}; // If we have more ones, we need to start with 1.
        else if (ones < zeroes)
            values = {0}; // If we have more zeroes, we need to start with 0.
        else
            values = {0, 1}; // We have the same number of zeroes and ones, we can start with 0 or 1.
        for (int value: values) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (rows[0][i] == rows[1][i]) {
                    count = INT_MAX;
                    break;
                }
                count += (rows[0][i] != value);
                value = 1 - value;
            }
            if (count != INT_MAX)
                res = min(res, (1 + count)/2);
        }

        return res;
    }

    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        int res = check(board);
        if (res == INT_MAX)
            return -1;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j)
                swap(board[i][j], board[j][i]);
        }
        int r = check(board);
        return r != INT_MAX ? res + r : r;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> board;

    // Output: 2
    board = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 0
    board = {{0,1},{1,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: -1
    board = {{1,0},{1,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 2
    board = {{1,1,0},{0,0,1},{0,0,1}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: -1
    board = {{0,0,1,1},{1,1,0,0},{0,1,0,1},{1,0,1,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 2
    board = {{0,1,1},{1,0,0},{1,0,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 3
    board = {{1,0,0,1,1},
             {0,1,1,0,0},
             {1,0,0,1,1},
             {0,1,1,0,0},
             {0,1,1,0,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 3
    board = {{1,1,1,0,0,1,0,0},
             {0,0,0,1,1,0,1,1},
             {1,1,1,0,0,1,0,0},
             {0,0,0,1,1,0,1,1},
             {0,0,0,1,1,0,1,1},
             {0,0,0,1,1,0,1,1},
             {1,1,1,0,0,1,0,0},
             {1,1,1,0,0,1,0,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 2
    board = {{0,1,0,0,0,1,1,1,0,1},
             {0,1,0,0,0,1,1,1,0,1},
             {1,0,1,1,1,0,0,0,1,0},
             {1,0,1,1,1,0,0,0,1,0},
             {1,0,1,1,1,0,0,0,1,0},
             {0,1,0,0,0,1,1,1,0,1},
             {1,0,1,1,1,0,0,0,1,0},
             {0,1,0,0,0,1,1,1,0,1},
             {1,0,1,1,1,0,0,0,1,0},
             {0,1,0,0,0,1,1,1,0,1}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 5
    board = {{1,1,1,0,0,0,1,1,0,0,0,1},
             {0,0,0,1,1,1,0,0,1,1,1,0},
             {0,0,0,1,1,1,0,0,1,1,1,0},
             {1,1,1,0,0,0,1,1,0,0,0,1},
             {0,0,0,1,1,1,0,0,1,1,1,0},
             {1,1,1,0,0,0,1,1,0,0,0,1},
             {0,0,0,1,1,1,0,0,1,1,1,0},
             {1,1,1,0,0,0,1,1,0,0,0,1},
             {1,1,1,0,0,0,1,1,0,0,0,1},
             {1,1,1,0,0,0,1,1,0,0,0,1},
             {0,0,0,1,1,1,0,0,1,1,1,0},
             {0,0,0,1,1,1,0,0,1,1,1,0}};
    cout << sol.movesToChessboard(board) << endl;

    // Output: 6
    board = {{0,0,1,1,0,0,0,1,1,0,1,1,1,0},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {0,0,1,1,0,0,0,1,1,0,1,1,1,0},
             {0,0,1,1,0,0,0,1,1,0,1,1,1,0},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {0,0,1,1,0,0,0,1,1,0,1,1,1,0},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {0,0,1,1,0,0,0,1,1,0,1,1,1,0},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {0,0,1,1,0,0,0,1,1,0,1,1,1,0},
             {1,1,0,0,1,1,1,0,0,1,0,0,0,1},
             {0,0,1,1,0,0,0,1,1,0,1,1,1,0}};
    cout << sol.movesToChessboard(board) << endl;

    return 0;
}
