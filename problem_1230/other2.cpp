class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {

        int n = prob.size();
        vector<double> dp(target + 1, 0.0);

        if(target) dp[1] = prob[0];
        dp[0] = 1.0 - prob[0];
        for(int i = 1; i < n; i ++){
            for(int j = target; j >= 1; j --)
                dp[j] = dp[j] * (1 - prob[i]) + dp[j - 1] * prob[i];
            dp[0] = dp[0] * (1 - prob[i]);
        }
        return dp[target];
    }
};
