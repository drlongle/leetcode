class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        int n = A.size();
        vector<int> dp(n);
        dp[0] = A[0];
        for(int i = 1; i < n; i++) {
            int mx = A[i];
            int curr = INT_MIN;
            for(int j = 1; j <= k && i - j + 1 >= 0; j++) {
                mx = max(mx, A[i - j + 1]);
                if(i - j + 1 == 0)
                    curr = max(curr, j * mx);
                else
                    curr = max(curr, dp[i - j] + j * mx);
            }
            dp[i] = curr;
        }
        return dp[n - 1];
    }
};
