class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        int c = sum / k;
        if (c * k != sum) return false;
        vector<int> dp(1 << n);
        for (int i = 1; i < 1 << n; i++) {
            dp[i] = sum;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) && dp[i ^ (1 << j)] + nums[j] <= c) {
                    auto a = dp[i ^ (1 << j)];
                    a = (a + nums[j]) % c;
                    dp[i] = min(dp[i], a);
                }
            }
        }
        return !dp.back();
    }
};
