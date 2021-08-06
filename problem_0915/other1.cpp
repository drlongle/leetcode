class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans=0,maxi=INT_MIN,tempmax=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<tempmax)
            {
                ans=i;
                tempmax=maxi;
            }
            maxi=max(nums[i],maxi);
        }
        return ans+1;
    }
};
