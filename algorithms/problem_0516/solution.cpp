/*
516. Longest Palindromic Subsequence
Medium

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
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
#include <memory>
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
    int longestPalindromeSubseq(string s) {
        int sz = s.size(), res = 0;
        vector<vector<int>> dp(sz, vector<int>(sz, -1));
        for (int len = 1; len <= sz; ++len) {
            for (int i = 0; i <= sz - len; ++i) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][i] = 1;
                } else if (len == 2) {
                    dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
