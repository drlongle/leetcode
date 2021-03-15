class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), result = 0;
        vector<vector<int>> dp(n, vector<int>(1001, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int different = A[j] - A[i] + 500;
                if (dp[j][different] == -1) dp[i][different] = max(dp[i][different], 2);
                else dp[i][different] = max(dp[i][different], dp[j][different] + 1);
                result = max(result, dp[i][different]);
            }
        }
        return result;
    }
};
