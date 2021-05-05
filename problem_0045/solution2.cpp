class Solution {
public:
    vector<int> dp;

    int jump(vector<int>& nums, int index) {
        if (index == nums.size() -1)
            return 0;
        int& res = dp[index];
        if (res >= 0)
            return res;
        res = INT_MAX;
        for (int i = 1; i <= nums[index] && index + i < nums.size(); ++i) {
            int t = jump(nums, index + i);
            if (t == INT_MAX)
                continue;
            res = min(res, 1 + t);
        }
        return res;
    }

    int jump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return jump(nums, 0);
    }
};