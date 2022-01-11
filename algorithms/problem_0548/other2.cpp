class Solution {
public:
    bool splitArray(vector<int>& nums) {
        vector<int> sum(nums.size(),0);
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            sum[i]=sum[i-1]+nums[i];
        int n=nums.size();
        int total=sum[n-1];
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);

        for(int i=1;i<n-1;i++)
        {
            int v1=sum[i]-nums[i];
            for(int j=i+2;j<n-1;j++)
            {
                int v2=sum[j]-sum[i]-nums[j];
                if(v1!=v2) continue;
                int idx=total-sum[j]-2*v1;
                if(mp.count(idx)!=0)
                {
                    auto vec=mp[idx];
                    for(int v3:vec)
                    {
                        if(v3>j+1)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
