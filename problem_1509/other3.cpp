class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i <= 3; ++i)
            ans = min(ans, nums[n - 3 + i] - nums[i]);
        return ans;
    }
};
