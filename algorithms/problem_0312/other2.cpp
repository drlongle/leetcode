class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int L = n - 1; L >= 0; L--) {
            for(int R = L; R < n; R++) {
                dp[L][R] = INT_MIN;
                for(int i = L; i <= R; i++) {
                    dp[L][R] = max(dp[L][R], (L+ 1 > i ? 0 : dp[L][i - 1]) + (i + 1  > R ? 0 : dp[i + 1][R]) + (
                        L == 0 ? 1 : nums[L - 1]) * nums[i] *(R == n - 1 ? 1 : nums[R + 1]));
                }
            }
        }
        return dp[0][n - 1];
    }
};

