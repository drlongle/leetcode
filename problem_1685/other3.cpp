class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> suffix(n);

        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] + nums[i];

        int cum = 0;
        for(int i = 0; i < n; i++)
        {
            cum += nums[i];
            ans[i] = abs(suffix[i]-nums[i]*(n-i)) + abs(cum-nums[i]*(i+1));
        }
        return ans;
    }
};
