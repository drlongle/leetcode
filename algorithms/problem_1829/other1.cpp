class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int sum = pow(2, maximumBit) - 1;
        int n = nums.size();
        vector<int> ans(n, 0);

        int res = 0;
        for(int i=0; i<n; ++i) {
            res = res ^ nums[i];
            ans[n-1-i] = sum - res;
        }
        return ans;
    }
};
