class Solution {

public:
    double probabilityOfHeads(vector<double>& prob, int target) {

        int n = prob.size();
        vector<vector<double>> dp(2, vector<double>(target + 1, 0.0));
        if(target) dp[0][1] = prob[0];
        dp[0][0] = 1.0 - prob[0];
        for(int i = 1; i < n; i ++){
            dp[i % 2][0] = dp[(i - 1) % 2][0] * (1 - prob[i]);
            for(int j = 1; j <= target; j ++)
                dp[i % 2][j] = dp[(i - 1) % 2][j] * (1 - prob[i]) + dp[(i - 1) % 2][j - 1] * prob[i];
        }
        return dp[(n - 1) % 2][target];
    }
};
