class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        vector<int> ans(nums.size());
        inclusive_scan(nums.begin(), nums.end(), ans.rbegin(), bit_xor(), (1<<mb) - 1);
        return ans;
    }
};
