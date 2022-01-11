/*
1541. Minimum Insertions to Balance a Parentheses String
Medium

Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

Example 1:
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching.
We need to to add one more ')' at the end of the string to be "(())))" which is balanced.

Example 2:
Input: s = "())"
Output: 0
Explanation: The string is already balanced.

Example 3:
Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.

Example 4:
Input: s = "(((((("
Output: 12
Explanation: Add 12 ')' to balance the string.

Example 5:
Input: s = ")))))))"
Output: 5
Explanation: Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes "(((())))))))".

Constraints:
1 <= s.length <= 10^5
s consists of '(' and ')' only.
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

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int res = 0, cnt = 0;
        bool prev_close = false;
        for (char ch: s) {
            if (ch == '(') {
                if (prev_close) {
                    ++res;
                    cnt -= 2;
                    if (cnt < 0) {
                        ++res;
                        cnt += 2;
                    }
                }
                cnt += 2;
                prev_close = false;
            } else {
                if (prev_close) {
                    cnt -= 2;
                    if (cnt < 0) {
                        cnt += 2;
                        ++res;
                    }
                    prev_close = false;
                } else
                    prev_close = true;
            }
        }

        if (cnt == 0 && prev_close) {
            return res + 2;
        }
        return res + cnt - prev_close;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 1
    s = "(()))";
    cout << sol.minInsertions(s) << endl;

    // Output: 0
    s = "())";
    cout << sol.minInsertions(s) << endl;

    // Output: 3
    s = "))())(";
    cout << sol.minInsertions(s) << endl;

    //Output: 12
    s = "((((((";
    cout << sol.minInsertions(s) << endl;

    // Output: 5
    s = ")))))))";
    cout << sol.minInsertions(s) << endl;

    // Output: 7
    s = "()()()()()(";
    cout << sol.minInsertions(s) << endl;

    // Output: 2
    s = "()())))";
    cout << sol.minInsertions(s) << endl;

    // Output: 4
    s = "(()))(()))()())))";
    cout << sol.minInsertions(s) << endl;

    // Output: 7
    s = ")))((";
    cout << sol.minInsertions(s) << endl;

    // Output: 28
    s = ")))()))))))((()))())))()))))()))()())((()()))()(())()())()()))))))()()((()))(";
    cout << sol.minInsertions(s) << endl;

    return 0;
}
