/*
1138. Alphabet Board Path
Medium

On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.

We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

Example 1:
Input: target = "leet"
Output: "DDR!UURRR!!DDD!"

Example 2:
Input: target = "code"
Output: "RR!DDRR!UUL!R!"
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

const vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};

struct Pos {
    Pos(): mx(-1), my(-1) {}
    Pos(int x, int y): mx(x), my(y) {}
    int mx, my;
};

class Solution {
public:
    string alphabetBoardPath(string target) {
        ostringstream oss;
        unordered_map<char, Pos> lookup;
        for (int i = 0; i < static_cast<int>(board.size()); ++i) {
            for (int j = 0; j < static_cast<int>(board[i].size()); ++j) {
                lookup.emplace(board[i][j], Pos(i, j));
            }
        }
        Pos curr(0, 0);
        for (char ch: target) {
            Pos next = lookup[ch];
            int dx = next.mx - curr.mx;
            int dy = next.my - curr.my;

            if (dy < 0) {
                oss << string(-dy, 'L');
            }
            if (dx > 0) {
                oss << string(dx, 'D');
            }
            if (dx < 0) {
                oss << string(-dx, 'U');
            }
            if (dy > 0) {
                oss << string(dy, 'R');
            }

            oss << '!';
            curr = next;
        }
        
        return oss.str();
    }
};

int main()
{
    Solution sol;
    string target;

    // Expected: "DDR!UURRR!!DDD!"
    target = "leet";

    // Expected: "RR!DDRR!UUL!R!"
    target = "code";

    // Expected: "DDDDD!UUUUURRR!DDDDLLLD!"
    target = "zdz";

    target = "zzz";
    
    cout << "Result: " << sol.alphabetBoardPath(target) << endl;

    return 0;
}

