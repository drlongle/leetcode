class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(), n= B.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_len=INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(A[i] == B[j]) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j-1]+1;
                }
                max_len=max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};
