class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<int> dp(n, 1e5), ans;
        dp[n-1] = A[n-1];

        if (A[n-1] == -1) return ans;

        for (int i=n-2; i>=0; i--) {
            if (A[i]==-1) continue;
            for (int j=i+1; j<=min(n-1, i+B); j++)
                dp[i] = min(dp[i], A[i]+dp[j]);
        }

        if (dp[0]==1e5) return ans;

        int last = 1;
        for (int i=2; i<=n; i++) {
            if (dp[i-1]==dp[last-1]-A[last-1]) {
                ans.push_back(last);
                last = i;
            }
        }
        ans.push_back(n);
        return ans;
    }
};
