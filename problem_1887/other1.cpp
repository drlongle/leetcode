class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        map<int,int>::iterator it;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int i=0;
        int ans=0;
        for(it=mp.begin();it!=mp.end();it++){
            if(i==0){
                i++;
                continue;
            }
            else{
                ans+=i*it->second;i++;

            }
        }
        return ans;
    }
};
