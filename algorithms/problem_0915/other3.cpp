class Solution {
public:

    int partitionDisjoint(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;
        int maxx = nums[0];
        int ma  = nums[0];
        for(int i=1;i<n-1;i++)
        {
            ma = max(ma,nums[i]);
            if(nums[i]<maxx)
            {
                maxx = ma;
                ans = i;
            }
        }
        return ans+1;
    }
};