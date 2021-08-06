class Solution {
public:
    int maxA(int N) {
        int dp[] = {0, 1, 2, 3, 4, 5};
        for (auto i = 5; i <= N; ++i)
            for (auto j = i - 5; j < i - 2; ++j)
                dp[i % 6] = max(dp[i % 6], dp[j % 6] * (i - j - 1));
            return dp[N % 6];
    }
};