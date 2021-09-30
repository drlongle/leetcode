class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)return true;
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=0;
        for(int i=0;i<nums.size();++i)
            sum+=nums[i];
        if(sum%k!=0)
            return false;
        sum=sum/k;
        vector<int> res(k,0);
        return solve(0,sum,nums,res,k);
    }
    bool solve(int i,int sum,vector<int> & nums,vector<int>& res,int k){
        if(i==nums.size())
            return check(sum,res);

        // Find a bucket for nums[i]
        for(int j=0;j<=min(i,k-1);++j){
            if(res[j]+nums[i] > sum) continue;
            res[j]+=nums[i];
            if(solve(i+1,sum,nums,res,k)) return true;
            res[j]-=nums[i];
        }
        return false;
    }
    bool check(int sum,vector<int>& res){
        for(int i=0;i<res.size();++i){
            if(res[i]!=sum)return false;
        }
        return true;
    }
};