/*
dp[i] tracks max number of A's after i presses. For each dp[i] : i>=1, we try using the best buffer
from all smaller j's, dp[j], and pasting it i-j-2 times (-2 since we need to ctrl a ctrl c first).
*/

class Solution {
public:
    int maxA(int n) {
        int dp[n+1]; dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=0;j<i-2;j++)
                dp[i]=max(dp[i],(i-j-2)*dp[j]+dp[j]);
        }
        return dp[n];
    }
};
