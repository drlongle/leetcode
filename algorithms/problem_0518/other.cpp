class Solution {
public:
    int change(int t, vector<int>& cs) {
        vector<int> dp(t+1, 0);
        dp[0] = 1;
        for (auto c : cs)
            for (auto j = c; j <= t; ++j) dp[j] += dp[j - c];
        return dp[t];
    }
};
