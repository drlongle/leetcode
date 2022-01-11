class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        cost.push_back(0);
        vector<int> dp(sz+1);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i <= sz; ++i) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return dp[sz];
    }
};