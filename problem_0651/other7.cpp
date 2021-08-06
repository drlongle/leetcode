class Solution {
public:
    int maxA(int N) {
        if(N==0) return 0;
        if(N==1) return 1;
        if(N==2) return 2;
        vector<int> dp(N+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=N;i++)
        {
            dp[i]=i;
            for(int j=2;j<=i-3;j++)
            {
                dp[i]=max(dp[i],dp[j]+(i-j-2)*dp[j]);
            }
        }

        return dp[N];
    }
};
