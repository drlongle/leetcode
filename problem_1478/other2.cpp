class Solution {
public:
int minDistance(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        vector<int> B(n + 1, 0), dp(n, 1e6);
        for (int i = 0; i < n; ++i)
            B[i + 1] = B[i] + A[i];
        for (int k = 1; k <= K; ++k)
            for (int j = n - 1; j > k - 2; --j)
                for (int i = k - 2; i < j; ++i) {
                    int m1 =  (i + j + 1) / 2, m2 = (i + j + 2) / 2;
                    int last = (B[j + 1] - B[m2]) - (B[m1 + 1] - B[i + 1]);
                    dp[j] = min(dp[j], (i >= 0 ? dp[i] : 0) + last);
                }
        return dp[n - 1];
    }
};