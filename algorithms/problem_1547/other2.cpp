/*
Intuition
Similar to the problem 1000. Minimum Cost to Merge Stones.

Instead of considering the cost to cut,
we can transform the problem to the cost to stick all sticks.

Then we have the problem "merge stones".
Though in the format of dp, they are exaCtly the same.

Explanation
Add the "cut" index 0 and n, then sort all stick position.
dp[i][j] means the minimum cost to stick all sticks between A[i] and A[j]
 */

class Solution {
public:
    int minCost(int n, vector<int>& A) {
        A.push_back(0);
        A.push_back(n);
        sort(A.begin(), A.end());
        int k = A.size();
        vector<vector<int>> dp(k, vector<int>(k));
        for (int d = 2; d < k; ++d) {
            for (int i = 0; i < k - d; ++i) {
                dp[i][i + d] = 1e9;
                for (int m = i + 1; m < i + d; ++m) {
                    dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + A[i + d] - A[i]);
                }
            }
        }
        return dp[0][k - 1];
    }
};