class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // DP: dp[i][j] is the minimum cost of jth house painted by ith color. Here we have:
        // dp[0][j] is the min cost of jth house painted by red, dp[1][j] painted by blue, and dp[2][j] by green.
        // To calculate dp[i][j], we have following formula:
        // 1) dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + costs[j][0];
        // 2) dp[1][j] = min(dp[0][j - 1], dp[2][j - 1]) + costs[j][1];
        // 3) dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + costs[j][2].
        // Initial condition is dp[i][0] = costs[0][i]. The final result is (saying n is number of the houses):
        // min(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]).
        // Optimize: since we only need the values at previous column, we don't need a matrix.
        if (costs.empty())
        {
            return 0;
        }

        int size = costs.size();
        vector<int> dp{costs[0]};
        for (int i = 1; i < size; ++i)
        {
            int red = min(dp[1], dp[2]) + costs[i][0];
            int blue = min(dp[0], dp[2]) + costs[i][1];
            int green = min(dp[0], dp[1]) + costs[i][2];
            dp = {red, blue, green};
        }

        return min(min(dp[0], dp[1]), dp[2]);
    }
};
