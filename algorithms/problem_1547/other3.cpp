/*
To simplify the code, we insert 0 and n into the A.

Let dp[i][j] be the minimum cost if we cut on the stick from A[i] to A[j].

- If j == i + 1 (len == 2), we can't cut on this stick, so dp[i][j] = 0.
- If j == i + 2 (len == 3), the only choice you have is to cut in the middle, and the cost is the length of this stick,
  so dp[i][j] = A[i + 2] - A[i].
- If j > i + 2 (len >= 4), we can try to cut at k where i < k < j and use the minimum cost we can get which is the cost
  of cutting the left part dp[i][k] plus the cost of cutting the right part dp[k][j] and the cost of the current cut
  A[j] - A[i], so dp[i][j] = min( dp[i][k] + dp[k][j] + A[j] - A[i] | i < k < j)

The answer is dp[0][N-1].
 */

class Solution {
public:
    int minCost(int n, vector<int>& A) {
        A.push_back(0);
        A.push_back(n);
        sort(begin(A), end(A));
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N - 1; ++i) dp[i][i + 1] = 0;
        for (int i = 0; i < N - 2; ++i) dp[i][i + 2] = A[i + 2] - A[i];
        for (int len = 4; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[j] - A[i]);
            }
        }
        return dp[0][N - 1];
    }
};
