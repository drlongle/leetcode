class Solution {
public:
    int countArrangement(int n) {
        int dp[n+1][(1<<n)+1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int mask = 0; mask < (1<<n); mask++){
                dp[i][mask] = 0;
                for(int j = 0; j < n; j++){
                    if( (mask&(1<<j)) and (!((j+1)%i) or !(i%(j+1))) ){
                        dp[i][mask] += dp[i-1][mask^(1<<j)];
                    }
                }
            }
        }

        return dp[n][(1<<n)-1];
    }
};
