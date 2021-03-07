class Solution {
    int dp[1000][1000]={};
public:
    int solve(vector<int> &nums,int l,vector<int> &multipliers,int idx){
        if(idx>=multipliers.size())
            return 0;
        int r=nums.size()-(idx-l)-1;
        return dp[l][idx] ? dp[l][idx] : dp[l][idx]=
                                                 max(solve(nums,l+1,multipliers,idx+1)+multipliers[idx]*nums[l],
                                                     solve(nums,l,multipliers,idx+1)+multipliers[idx]*nums[r]);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return solve(nums,0,multipliers,0);

    }
};
