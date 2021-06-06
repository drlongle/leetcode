class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        sort(nums.begin(), nums.end());

        int ans = 1, count=1, f = nums[0];

        for(int i=1;i<n;i++)
        {
            if(nums[i]==(f+1))
            {
                f=nums[i];
                count++;
                ans=max(ans, count);
            }
            else if(nums[i]==(f))
            {
                continue;
            }
            else if(nums[i]!=(f+1))
            {
                f=nums[i];
                count=1;
            }
        }
        return ans;
    }
};
