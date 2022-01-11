class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = (int)stoneValue.size();
        vector<int> postSum(n + 1, 0);
        for (int i=n-1; i>=0; --i)
            postSum[i] = postSum[i + 1] + stoneValue[i];
        
        vector<int> dp(n, -50000 * 1000);
        for (int i = n - 1; i > max(-1, n - 4); --i)
            dp[i] = postSum[i];
        
        for (int i = n - 2; i >= 0; --i) {
            int bobScore = 50000* 1000;
            for (int j = 1; j < 4; ++j)
                if (i + j < n) bobScore = min(bobScore, dp[i + j]);
            dp[i] = max(dp[i], postSum[i] - bobScore);
        }
        int alice = dp[0], bob = postSum[0] - dp[0];
        return alice == bob ? "Tie": alice > bob ? "Alice": "Bob";
    }
};
