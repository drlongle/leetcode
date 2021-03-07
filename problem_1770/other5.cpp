class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(1000, vector<int>(1000, -1));

    int solve(uint lo, uint midx, vector<int>& nums, vector<int>& mult) {
        if (midx >= mult.size())
            return 0;
        if (dp[lo][midx] != -1)
            return dp[lo][midx];
        int left = mult[midx] * nums[lo] + solve(lo+1, midx+1, nums, mult);
        int right = mult[midx] * nums[nums.size() -1 -(midx-lo)] + solve(lo, midx+1, nums, mult);
        return dp[lo][midx] = max(left, right);
    }

    int maximumScore(vector<int>& nums, vector<int>& mult) {
        return solve(0, 0, nums, mult);
    }
};
