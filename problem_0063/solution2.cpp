class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = !grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || grid[i][j])
                    continue;
                dp[i][j] += (i > 0) ? dp[i-1][j] : 0;
                dp[i][j] += (j > 0) ? dp[i][j-1] : 0;
            }
        }

        return dp[m-1][n-1];
    }
};