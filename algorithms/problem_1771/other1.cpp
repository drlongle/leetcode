/*
To find the longest palindromic subsequence, see problem 516. Longest Palindromic Subsequence.

The trick is to how to enforce the rule that characters should come from the both strings.

So, we run the base algorithm on the concatenated string. At this point, our tabulation dp stores all
interim solutions. Then, we reuse the tabulation dp and only consider i and j where w1[i] == w2[j].

As additional optimization, for each i, we move j right-to-left, and break after
we find w1[i] == w2[j]. In other word, we only consider the "widest" matching pairs.

Update: you can collect first/last indexes of each 26 letters from both strings,
and do the matching pair check in O(1). See the optimized solution below!
*/

class Solution {
public:
    int longestPalindromeSubseq(string s, vector<vector<int>> &dp) {
        for (int len = 1; len <= s.size(); ++len)
            for (auto i = 0; i + len <= s.size(); ++i)
                dp[i][i + len] = s[i] == s[i + len - 1] ?
                                 dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2) :
                                 max(dp[i][i + len - 1],  dp[i + 1][i + len]);
        return dp[0][s.size()];
    }

    int longestPalindrome(string w1, string w2) {
        int sz = w1.size() + w2.size(), res = 0;
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1));
        vector<int> pos1(26, INT_MAX), pos2(26, -1);
        for (auto i = 0; i < w1.size(); ++i)
            pos1[w1[i] - 'a'] = min(pos1[w1[i] - 'a'], i);
        for (auto i = 0; i < w2.size(); ++i)
            pos2[w2[i] - 'a'] = max(pos2[w2[i] - 'a'], i);
        longestPalindromeSubseq(w1 + w2, dp);
        for (auto i = 0; i < 26; ++i)
            if (pos1[i] != INT_MAX && pos2[i] != -1)
                res = max(res, dp[pos1[i]][w1.size() + pos2[i] + 1]);
        return res;
    }
};
