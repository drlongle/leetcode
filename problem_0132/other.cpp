int minCut(string s) {
        int n =s.size();
        vector<int> dp(n+1,0);
         for (int i = 0; i <=n; ++i) dp[i] = n -i -1;
         vector<vector<bool>> m (n, vector<bool>(n, false));
         for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || m[i + 1][j - 1])) {
                    m[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1); 
                }
            }
        }
       return dp[0]; 
    }

