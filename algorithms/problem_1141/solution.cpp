/*
1143. Longest Common Subsequence
Medium

Given two strings text1 and text2, return the length of their longest common
subsequence. A subsequence of a string is a new string generated from the
original string with some characters(can be none) deleted without changing
the relative order of the remaining characters. (eg, "ace" is a subsequence
of "abcde" while "aec" is not). A common subsequence of two strings is a
subsequence that is common to both strings.

If there is no common subsequence, return 0. 

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3 
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if (!n1 || !n2)
            return 0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        return dp[n1][n2];
    }
};

int main()
{
    Solution sol;
    string text1, text2;

    // Expected: 3
    text1 = "abcde", text2 = "ace";

    // Expected: 3
    //text1 = "abc", text2 = "abc";

    // Expected: 0
    //text1 = "abc", text2 = "def";

    // Expected: 3
    text1 = "abcde", text2 = "badcfe";

    // Expected: 4
    text1 = "abcde", text2 = "oaebdcfe";

    cout << "Result: " << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
