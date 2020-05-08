class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k)
    {   
        int n = nums.size();
        vector<int> dp(n);
        deque<int> q;
        
        dp[0]=nums[0];
        q.push_back(0);
        int ans=dp[0];
        
        for(int i=1;i<n;i++)
        {   
            dp[i] = max(0,dp[q.front()]) + nums[i];
            ans=max(ans,dp[i]);
            
            while(!q.empty() && q.front()<=i-k)  //Similar to sliding window maximum problem
                q.pop_front();
            while(!q.empty() && dp[i]>=dp[q.back()])
                q.pop_back();
            q.push_back(i);
            
        }
        return ans;
    }
};
