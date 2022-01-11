class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int ms = multipliers.size(), ns = nums.size();
        int dp[ms + 1];
        dp[0] = 0;
        for (int mp = 0; mp < ms; ++mp) {
            int m = multipliers[mp], next = INT_MIN;
            for (int i = mp; i >= 0;) {
                dp[i + 1] = max(dp[i] + nums[i] * m, next);
                next = dp[i--];
                next += nums[ns - mp + i] * m;
            }
            dp[0] = next;
        }
        return *max_element(dp, dp + ms + 1);
    }
};
