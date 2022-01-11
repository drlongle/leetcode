class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=(int)A.size();
        vector<int> v(1001,0);
        v[0]=1;
        vector<vector<int>> dp(n,v);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int dif=A[i]-A[j]+500;
                if(dp[j][dif]==0) dp[i][dif]=2;
                else dp[i][dif]=max(dp[i][dif],1+dp[j][dif]);
                ans=max(ans,dp[i][dif]);
            }
        }
        return ans;
    }
};
