/*
Steps:
1. Define dp[i][j] :=f(s1[0..i-1], s2[0..j-1])
2. Set up border condtion dp[0][:] and dp[:][0].
3. Iteration and apply dp rules.
4. return dp[n1][n2]
*/

int numDistinct(string s2, string s1) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int i=0; i<=n2;++i) dp[0][i] = 1;
        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){ 
                if(s1[i-1]==s2[j-1]) dp[i][j] =dp[i][j-1 ]+dp[i - 1][j - 1];
                else dp[i][j]= dp[i][j - 1]; 
            }
        }
        return dp[n1][n2];        
    }

