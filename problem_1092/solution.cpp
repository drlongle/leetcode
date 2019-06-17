/*
1092. Shortest Common Supersequence
Difficulty: Hard

Given two strings str1 and str2, return the shortest string that has both
str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T
(possibly 0, and the characters are chosen anywhere from T) results in the string S.)
 
Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a substring of "cabac" because we can delete the first "c".
str2 = "cab" is a substring of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    string longestCommonSubsequence(const string& s1, const string& s2) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());
        vector<vector<string>> dp(m+1, vector<string>(n+1, ""));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j] + s1[i];
                else
                    dp[i+1][j+1] = dp[i+1][j].size() > dp[i][j+1].size() ? dp[i+1][j] : dp[i][j+1];
            }
        }
        return dp[m][n];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = longestCommonSubsequence(str1, str2);
        ostringstream oss;
        int i = 0, j = 0;
        for (char c: lcs) {
            while (str1[i] != c)
                oss << str1[i++];
            while (str2[j] != c)
                oss << str2[j++];
            oss << c;
            i++, j++;
        }
        oss << str1.substr(i);
        oss << str2.substr(j);
        return oss.str();
    }
};

int main() {
    Solution sol;
    string str1, str2;

    // Expected: "cabac"
    str1 = "abac", str2 = "cab";

    // 28 / 47 test cases passed.
    //str1 = "bcaaacbbbcbdcaddadcacbdddcdcccdadadcbabaccbccdcdcbcaccacbbdcbabb";
    //str2 = "dddbbdcbccaccbababaacbcbacdddcdabadcacddbacadabdabcdbaaabaccbdaa";

    cout << "Result: " << sol.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}

