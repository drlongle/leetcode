class Solution {
public:
    int maxA(int N) {
        // DP: dp[0][j] is maximum # of A when printing A at ith time,
        // dp[1][j] is max # of A when pressing ctrl-A at ith time,
        // dp[2][j] is max # of A when pressing ctrl-V at ith time,
        // The formula is:
        // 1) dp[0][j] = max(dp[0][j - 1], dp[1][j - 1], dp[2][j - 1], dp[3][j - 1]) + 1.
        // 2) dp[1][j] = max(dp[0][j - 1], dp[1][j - 1], dp[2][j - 1], dp[3][j - 1]).
        // 4) dp[2][j] = max(dp[1][j - 2] * 2, dp[1][j - 3] * 3, ... dp[1][0] * j), OR 0 for j < 2.
        // Final output should be max(dp[0][N - 1], dp[1][N - 1], dp[2][N - 1]).
        // Notice for ctrl-V, the maximum value could only happen for ctrl-A, ctrl-C, ctrl-V, OR
        // ctrl-V, ... ctrl-V, aka 1 copy paste or multiple pastes.
        vector<vector<int>> dp(4, vector<int>(N));
        for (int i = 0; i < N; ++i)
        {
            dp[0][i] = 1 + (i > 0 ? max(max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]), dp[3][i - 1]) : 0);
            dp[1][i] = i > 0 ? max(max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]), dp[3][i - 1]) : 0;
            dp[2][i] = 0;

            for (int j = i - 2; j >= 0; --j)
            {
                int paste = dp[1][j] * (i - j);
                dp[2][i] = paste > dp[2][i] ? paste : dp[2][i];
            }
        }

        return max(max(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]);
    }
};
