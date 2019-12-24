class Solution {
public:
    int numWays(int steps, int arrLen) {
        int len= steps<arrLen?steps:arrLen;
        vector<long> dp(len, 0);
        int mod(1e9+7);
        dp[0]=1;
        dp[1]=1;
        for (int i=1; i<steps; i++)
        {
                vector<long> tmp(len, 0);
                for (int j=0; j<len; j++)
                {
                    tmp[j] = (dp[j]) % mod;
                    if (j - 1 >= 0) tmp[j] = (tmp[j] + dp[j - 1]) % mod;
                    if (j + 1 < len) tmp[j] = (tmp[j]+dp[j + 1]) % mod;
                    if (!tmp[j]) break;
                }
                dp=tmp;
        }
        return dp[0]% mod;
    }
};
