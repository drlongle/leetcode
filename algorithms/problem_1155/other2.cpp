class Solution {
  public:
    vector<vector<int>> dp;
    int numRollsToTarget(int n, int k, int target) {
        if (dp.size() == 0)
            dp = vector<vector<int>>(31, vector<int>(1000, -1));
        if (target == 0 && n == 0)
            return 1;
        if (target < 0 || n <= 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int total_ways = 0;
        for (int i = 1; i <= k; i++) {
            total_ways += numRollsToTarget(n - 1, k, target - i);
            total_ways = total_ways % 1000000007;
        }
        return dp[n][target] = total_ways;
    }
};
