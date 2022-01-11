class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto x: nums) mp[x]++;
        int size=mp.size()-1;
        int presum=0;
        int ans=0;
        for(auto i = mp.rbegin(); i!=mp.rend() and size;i++,size--)
        {
            presum+=i->second;
            ans+=presum;
        }

        return ans;
    }
};
