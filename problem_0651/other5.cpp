class Solution {
public:
    int maxA(int N) {
        int dp[N];
        if (N <= 4)     return N;
        for (int i = 0; i < N; i++) {
            if (i <= 3) {
                dp[i] = i + 1;
                continue;
            }
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j <= i - 3; j++) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }

        }

        return dp[N - 1];
    }
};
