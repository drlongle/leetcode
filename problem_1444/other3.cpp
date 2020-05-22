class Solution {
public:
  int ways(vector<string>& pizza, int K) {
    const int MOD = 1e9 + 7;
    const int n = pizza.size();
    const int m = pizza[0].length();
    
    int sum[n][m];
	
    for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--) {
      sum[i][j] = pizza[i][j] == 'A';
      if (i < n - 1) sum[i][j] += sum[i + 1][j];
      if (j < m - 1) sum[i][j] += sum[i][j + 1];
      if (i < n - 1 && j < m - 1) sum[i][j] -= sum[i + 1][j + 1];
    }
    
    int dp[n][m][K];
	
    for (int k = 0; k < K; k++)
    for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
	  if (k == 0) {
		dp[i][j][k] = sum[i][j] > 0;
	  } else {
		dp[i][j][k] = 0;
		for (int ii = i + 1; ii < n; ii++)
		  if (sum[i][j] - sum[ii][j] > 0) {
			dp[i][j][k] += dp[ii][j][k - 1];
			dp[i][j][k] %= MOD;
		  }
		for (int jj = j + 1; jj < m; jj++)
          if (sum[i][j] - sum[i][jj] > 0) {
			dp[i][j][k] += dp[i][jj][k - 1];
			dp[i][j][k] %= MOD;
		  }
	  }
    
    return dp[0][0][K - 1];
  }
};
