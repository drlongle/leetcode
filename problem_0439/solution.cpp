/*
439. Ternary Expression Parser
Medium

Given a string representing arbitrarily nested ternary expressions, calculate the result of the
expression. You can always assume that the given expression is valid and only consists of digits
0-9, ?, :, T and F (T and F represent True and False respectively).

Note:
The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.

Example 1:
Input: "T?2:3"
Output: "2"
Explanation: If true, then result is 2; otherwise result is 3.

Example 2:
Input: "F?1:T?4:5"
Output: "4"
Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"

Example 3:
Input: "T?T?F:5:3"
Output: "F"
Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    string eval(string& s, int i, int j) {
        if (i == j)
            return string(1, s[i]);
        int k, l, cnt = 1;
        for (k = i+2; k < j && cnt > 0; ++k) {
            if (s[k] == '?' || s[k] == ':') {
                l = k;
                if (s[k] == '?')
                    ++cnt;
                else
                    --cnt;
            }
        }
        if (s[i] == 'T')
            return eval(s, i+2, l-1);
        else
            return eval(s, l+1, j);
    }

    string parseTernary(string s) {
        return eval(s, 0, s.size() - 1);
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "2"
    s = "T?2:3";
    cout << sol.parseTernary(s) << endl;

    // Output: "4"
    s = "F?1:T?4:5";
    cout << sol.parseTernary(s) << endl;

    // Output: "F"
    s = "T?T?F:5:3";
    cout << sol.parseTernary(s) << endl;

    //"T?T:(F?(T?1:2):F?3:4)";

    // Expected: "T"
    s = "T?T:F?T?1:2:F?3:4";
    cout << sol.parseTernary(s) << endl;

    return 0;
}
