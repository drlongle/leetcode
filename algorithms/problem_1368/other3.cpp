/*
Within the loop, we first go right or down and record the min steps to the bottom right, then we go left or up to the top left. We repeat until the DP matrix remains the same.
The time complexity is O((m+n)mn), because we need to change O(m+n) signs to get a valid path in the worst case. The space complexity is O(mn).
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size());
        vector<vector<int>> dp(m, vector<int>(n, 10000));
        dp[0][0] = 0;
        
        while (true) {
            vector<vector<int>> temp(dp);
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    dp[i][j] = min(dp[i][j], min(i ? dp[i - 1][j] + (grid[i - 1][j] == 3 ? 0 : 1) : 10000, 
                                                 j ? dp[i][j - 1] + (grid[i][j - 1] == 1 ? 0 : 1) : 10000));
            // It depends on the complexity of pattern to break the loop
			if (temp == dp) break;
            for (int i = m - 1; i >= 0; --i)
                for (int j = n - 1; j >= 0; --j)
                    dp[i][j] = min(dp[i][j], min(i != m - 1 ? dp[i + 1][j] + (grid[i + 1][j] == 4 ? 0 : 1) : 10000,
                                                 j != n - 1 ? dp[i][j + 1] + (grid[i][j + 1] == 2 ? 0 : 1) : 10000));
        }
        
        return dp[m - 1][n - 1];
    }
};
