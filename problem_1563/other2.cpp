class Solution {
public:
    int dp[501][501] = {};
    int dfs(vector<int>& v, int i, int j) {
        if (!dp[i][j])
            for (int k = i; k < j; ++k) {
                int left = v[k] - (i > 0 ? v[i - 1] : 0), right = v[j] - v[k];
                if (left <= right)
                    dp[i][j] = max(dp[i][j], left + dfs(v, i, k));
                if (left >= right)
                    dp[i][j] = max(dp[i][j], right + dfs(v, k + 1, j));
            }
        return dp[i][j];
    }
    int stoneGameV(vector<int>& v) {
        partial_sum(begin(v), end(v), begin(v));
        return dfs(v, 0, v.size() - 1);
    }
};