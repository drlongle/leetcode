class Solution {
public:
    int strangePrinter(string s) {
        if(s.empty()) return 0;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }

        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j=i+l-1;
                dp[i][j]=1+dp[i+1][j];
                for(int k=i+1;k<=j;k++)
                {
                    if(s[i]==s[k])
                    {
                        dp[i][j]=min(dp[i][j],dp[i][k-1]+(k+1<n ? dp[k+1][j]:0));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
