class Solution {
public:
    Solution() {
        dp = vector<int>(51, 0);
        for(int i = 1; i <= 50; ++i) {
            dp[i] = max(dp[i-1]+1, dp[i]);
            for(int j = i+3, t = 2; j <= 50; ++j, ++t)
                dp[j] = max(dp[j], dp[i]*t);
        }
    }
    int maxA(int N) {
        return dp[N];
    }
    vector<int> dp;
};
