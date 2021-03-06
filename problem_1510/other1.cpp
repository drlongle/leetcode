class Solution {
public:
    bool winnerSquareGame(int n) {
        if(sqrt(n) - floor(sqrt(n)) == 0)
            return true;
        vector<bool> dp(n+1,false);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j*j <= i; ++j)
            {
                int x = j*j;
                if(!dp[i-x])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};