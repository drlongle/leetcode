/*
- For n = 2 , dp[2][LAST_TWO_SAME] would be equal to the colors possible for example if colors are rgb,
  one could have rr,gg and bb.
- For n = 2, dp[2][LAST_TWO_DIFF] would be a simple combination problem of k*(k-1).
- Going forward, dp[n][LAST_TWO_SAME] would be same as dp[n-1][LAST_TWO_DIFFER] since dp[n-1][LAST_TWO_SAME]
  cannot be further included and one could form dp[n][LAST_TWO_SAME] appending the last digit again,
  so there is one choice per combination of dp[n-1][LAST_TWO_DIFFER].
- For dp[n][LAST_TWO_DIFF], one could consider all the previous combinations and just append any digit
  apart from the digit that appears at the end, so basically one has k-1 choices.

The final answer would be the sum of both the scenarios dp[n][LAST_TWO_DIFFER] and dp[n][LAST_TWO_SAME].
*/

class Solution {
public:
    const int LAST_TWO_SAME = 0;
    const int LAST_TWO_DIFFER = 1;
    int numWays(int n, int k) {
        if(n == 0 || k == 0)
            return 0;
        if( n == 1)
            return k;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[2][LAST_TWO_SAME] = k, dp[2][LAST_TWO_DIFFER] = k*(k-1);
        for(int i = 3 ; i <= n ; i++)
        {
            dp[i][LAST_TWO_SAME] = dp[i-1][LAST_TWO_DIFFER];
            dp[i][LAST_TWO_DIFFER] = (dp[i-1][LAST_TWO_DIFFER] + dp[i-1][LAST_TWO_SAME])*(k-1);
        }
        return dp[n][LAST_TWO_SAME]+dp[n][LAST_TWO_DIFFER];
    }
};

