/*
639. Decode Ways II
Hard

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*',
which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
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
    static constexpr int MOD = 1000000007;
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '*')
                dp[i+1] = 9 * dp[i];
            else if (ch > '0')
                dp[i+1] = dp[i];
            if (i >= 1) {
                if (s[i-1] == '1')
                    dp[i+1] = (dp[i+1] + dp[i-1] * ((ch == '*') ? 9 : 1)) % MOD;
                if (s[i-1] == '2' && (ch == '*' || ch <= '6')) {
                    dp[i+1] = (dp[i+1] + dp[i-1] * ((ch == '*') ? 6 : 1)) % MOD;
                }
                if (s[i-1] == '*') {
                    dp[i+1] = (dp[i+1] + dp[i-1] * ((ch == '*') ? 9 : 1)) % MOD;
                    if (ch == '*' || ch <= '6')
                        dp[i+1] = (dp[i+1] + dp[i-1] * ((ch == '*') ? 6 : 1)) % MOD;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 9
    s = "*";
    cout << sol.numDecodings(s) << endl;

    // Output: 18
    s = "1*";
    cout << sol.numDecodings(s) << endl;

    // Output: 96
    s = "**";
    cout << sol.numDecodings(s) << endl;

    return 0;
}
