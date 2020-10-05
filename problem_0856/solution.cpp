/*
856. Score of Parentheses
Medium

Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Example 1:
Input: "()"
Output: 1

Example 2:
Input: "(())"
Output: 2

Example 3:
Input: "()()"
Output: 2

Example 4:
Input: "(()(()))"
Output: 6

Note:
S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50
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
    int scoreOfParentheses(string S) {
        int sz = S.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));

        for (int l = 2; l <= sz; l += 2) {
            for (int i = 0; i + l - 1 < sz; ++i) {
                int j = i + l - 1;
                if (S[i] != '(' || S[j] != ')')
                    continue;
                if (l == 2) {
                    dp[i][j] = 1;
                    continue;
                }
                int cnt = 0, prev = -1;
                for (int k = i; k <= j; ++k) {
                    if (cnt == 0)
                        prev = k;
                    cnt += S[k] == '(' ? 1 : -1;
                    if (cnt == 0) {
                        if (dp[prev][k] > 0)
                            dp[i][j] += dp[prev][k];
                        else {
                            dp[i][j] = -1;
                            break;
                        }
                    }
                }
                if (cnt != 0)
                    dp[i][j] = -1;
                else if (dp[i][j] < 0)
                    dp[i][j] = 2 * dp[i+1][j-1];
            }
        }

        return dp[0][sz-1];
    }
};

int main() {
    Solution sol;
    string S;

    // Output: 1
    S = "()";
    cout << sol.scoreOfParentheses(S) << endl;

    // Output: 2
    S = "(())";
    cout << sol.scoreOfParentheses(S) << endl;

    // Output: 2
    S = "()()";
    cout << sol.scoreOfParentheses(S) << endl;

    // Output: 3
    S = "(())()";
    cout << sol.scoreOfParentheses(S) << endl;

    // Output: 6
    S = "(()(()))";
    cout << sol.scoreOfParentheses(S) << endl;

    return 0;
}
