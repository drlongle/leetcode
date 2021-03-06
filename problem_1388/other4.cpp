class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        const int n(slices.size());
        int ans(0);
        vector<vector<int>> dp(2 * n, vector<int>(2 * n));
        
        for (int len = 3; len <= n; len += 3) {
            for (int i = 0; i + len - 1 < 2 * n; ++i) {
                int j = i + len - 1;
                // case 1: select [i:k-1] and [k:j] separately
                for (int k = i + 3; k < j; k += 3)
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k][j]);
                // case 2: select k from [i, k, j] after selecting [i+1:k-1] and [k+1:j-1]
                for (int k = i + 1; k <= j - 1; k += 3)
                    dp[i][j] = max(dp[i][j], dp[i+1][k-1] + slices[k % n] + dp[k+1][j-1]);
            }
        }
        
        for (int i = 0; i < n; ++i) 
            ans = max(ans, dp[i][i + n - 1]);
        
        return ans;
    }
};
