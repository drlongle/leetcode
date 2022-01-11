/*
712. Minimum ASCII Delete Sum for Two Strings
Medium

Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
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

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for (int i = 0, sum = 0; i < l1; ++i) {
            sum += s1[i];
            dp[i+1][0] = sum;

        }
        for (int i = 0, sum = 0; i < l2; ++i) {
            sum += s2[i];
            dp[0][i+1] = sum;

        }
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int t = numeric_limits<int>::max();
                    t = min(t, dp[i-1][j] + s1[i-1]);
                    t = min(t, dp[i][j-1] + s2[j-1]);
                    t = min(t, dp[i-1][j-1] + s1[i-1] + s2[j-1]);
                    dp[i][j] = t;
                }
            }
        }
        return dp[l1][l2];
    }
};

int main() {
    Solution sol;
    string s1, s2;

    // Output: 231
    s1 = "sea", s2 = "eat";
    cout << sol.minimumDeleteSum(s1, s2) << endl;

    // Output: 403
    s1 = "delete", s2 = "leet";
    cout << sol.minimumDeleteSum(s1, s2) << endl;

    return 0;
}
