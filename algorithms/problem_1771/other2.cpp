class Solution {
    int dp[2000][2000];
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int m = word1.length(), n = word2.length(), ans = 0;
        for (int j = 0; j < m + n; ++j) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 == j) ? 2 : dp[i+1][j-1] + 2;
                    if (i < m and j >= m) ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return ans;
    }
};
