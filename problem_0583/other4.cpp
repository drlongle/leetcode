class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs = LCS(word1, word2);
        return word1.size() + word2.size() - (2 * lcs);
    }

private:
    int LCS(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 0; i <= m; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = w1[i-1] == w2[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};
