class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]==nums[n-1])
        {
            return 0;
        }

        int ans=0;int c=1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]!=nums[i-1])
            {
                ans=ans+c;
            }
            c++;

        }
        return ans;

    }
};
