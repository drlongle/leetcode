/*
488. Zuma Game
Hard

You are playing a variation of the game Zuma.

In this variation of Zuma, there is a single row of colored balls on a board,
where each ball can be colored red 'R', yellow 'Y', blue 'B', green 'G', or
white 'W'. You also have several colored balls in your hand.

Your goal is to clear all of the balls from the board. On each turn:

Pick any ball from your hand and insert it in between two balls in the row or on
either end of the row. If there is a group of three or more consecutive balls of
the same color, remove the group of balls from the board. If this removal causes
more groups of three or more of the same color to form, then continue removing
each group until there are none left. If there are no more balls on the board,
then you win the game. Repeat this process until you either win or do not have
any more balls in your hand. Given a string board, representing the row of balls
on the board, and a string hand, representing the balls in your hand, return the
minimum number of balls you have to insert to clear all the balls from the
board. If you cannot clear all the balls from the board using the balls in your
hand, return -1.

Example 1:
Input: board = "WRRBBW", hand = "RB"
Output: -1
Explanation: It is impossible to clear all the balls. The best you can do is:
- Insert 'R' so the board becomes WRRRBBW. WRRRBBW -> WBBW.
- Insert 'B' so the board becomes WBBBW. WBBBW -> WW.
There are still balls remaining on the board, and you are out of balls to
insert.

Example 2:
Input: board = "WWRRBBWW", hand = "WRBRW"
Output: 2
Explanation: To make the board empty:
- Insert 'R' so the board becomes WWRRRBBWW. WWRRRBBWW -> WWBBWW.
- Insert 'B' so the board becomes WWBBBWW. WWBBBWW -> WWWW -> empty.
2 balls from your hand were needed to clear the board.

Example 3:
Input: board = "G", hand = "GGGGG"
Output: 2
Explanation: To make the board empty:
- Insert 'G' so the board becomes GG.
- Insert 'G' so the board becomes GGG. GGG -> empty.
2 balls from your hand were needed to clear the board.

Constraints:
1 <= board.length <= 16
1 <= hand.length <= 5
board and hand consist of the characters 'R', 'Y', 'B', 'G', and 'W'.
The initial row of balls on the board will not have any groups of three or more
consecutive balls of the same color.
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

namespace std {
template <> struct hash<pair<int, string>> {
    size_t operator()(const pair<int, string> &p) const {
        return hash<int>()(p.first) << 16 ^ hash<string>()(p.second);
    }
};
} // namespace std

class Solution {
  public:
    unordered_map<pair<int, string>, int> dp;
    unordered_set<pair<int, string>> seen;

    string simplify(string &s) {
        string r;
        char last_char = -1;
        int cnt = 0;
        for (char c : s) {
            if (c == last_char)
                ++cnt;
            else {
                if (cnt > 0 && cnt < 3)
                    r += string(cnt, last_char);
                last_char = c;
                cnt = 1;
                for (int i = r.size() - 1; i >= 0 && r[i] == c; --i) {
                    ++cnt;
                }
                if (cnt >= 2) {
                    for (int i = 1; i < cnt; ++i)
                        r.pop_back();
                }
            }
        }
        if (cnt > 0 && cnt < 3)
            r += string(cnt, last_char);
        // cout << "simplify: " << s << " -> " << r << endl;
        return r;
    }

    map<char, int> lookup{{'R', 0}, {'Y', 1}, {'B', 2}, {'G', 3}, {'W', 4}};
    string reverse_lookup{'R', 'Y', 'B', 'G', 'W'};

    int minStep(string &board, int counters) {
        if (board.empty())
            return 0;
        int res = INT_MAX;
        if (counters == 0)
            return res;

        auto key = make_pair(counters, board);
        auto it = dp.find(key);
        if (it != dp.end())
            return it->second;

        string s;
        char last_char = 0;
        int cnt = 0;
        for (int i = 0, sz = board.size(); i <= sz; ++i) {
            int p = pow(10, 4);
            for (int j = 4; j >= 0; --j, p /= 10) {
                char add_char = reverse_lookup[j];
                if (i == 0 ||
                    (add_char != last_char &&
                     ((i == sz) || (i < sz && last_char != board[i]))))
                    continue;
                int added = 0;
                int limit = (last_char == add_char) ? 3 - cnt : 1;
                while (counters % (10 * p) >= (added + 1) * p &&
                       added < limit) {
                    s.push_back(add_char);
                    string bb = s + board.substr(i);
                    string new_board = simplify(bb);
                    ++added;
                    auto new_key = make_pair(counters - added * p, new_board);
                    if (seen.insert(new_key).second) {
                        auto t = minStep(new_board, counters - p);
                        // cout << "bb: " << bb << ", new_board: " << new_board
                        // << " -> " << t << endl;
                        if (t != INT_MAX)
                            res = min(res, 1 + t);
                    }
                }
                if (added > 0) {
                    s.resize(s.size() - added);
                }
            }
            if (i < sz) {
                char ch = board[i];
                s.push_back(ch);
                if (ch != last_char) {
                    cnt = 1;
                    last_char = ch;
                } else
                    ++cnt;
            }
        }

        // cout << "board: " << board << ", hand: " << hand << ", res: " << res
        // << endl;
        return dp[key] = res;
    }

    int findMinStep(string &board, string &hand) {
        seen.clear();

        int counters = 0;
        for (char c : hand) {
            counters += pow(10, lookup[c]);
        }

        int res = minStep(board, counters);
        return (res == INT_MAX) ? -1 : res;
    }
};

int main() {
    Solution sol;
    string board, hand;

    // Expected: -1
    board = "WRRBBW", hand = "RB";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 2
    board = "WWRRBBWW", hand = "WRBRW";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 2
    board = "G", hand = "GGGGG";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: -1
    board = "WWBBWBBWW";
    hand = "BB";
    // cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
    // << endl;

    // Expected: 2
    board = "WWRRBBWW";
    hand = "WRBRW";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 2
    board = "RRWWRRBBRR";
    hand = "WB";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 5
    board = "RRYGGYYRRYYGGYRR";
    hand = "GGBBB";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 3
    board = "YRRYYRRYYRYYR";
    hand = "YRRY";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 5
    board = "RYYRRYYRYRYYRYYR";
    hand = "RRRRR";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: -1
    board = "RRGGBBYYWWRRGGBB";
    hand = "RGBYW";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    // Expected: 3
    board = "RBYYBBRRB";
    hand = "YRBGB";
    cout << board << ", " << hand << " -> " << sol.findMinStep(board, hand)
         << endl;

    return 0;
}
