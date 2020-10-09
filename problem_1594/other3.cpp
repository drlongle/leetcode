class Solution {
public:
    int maxProductPath(vector<vector<int>>& g)
    {
        vector<vector<vector<long>>> dp(g.size(), vector<vector<long>>(g[0].size(), { INT_MAX, INT_MIN }));
        dp[0][0] = { g[0][0], g[0][0] };

        for (int row = 1; row < g.size(); ++row)
            dp[row][0] = { g[row][0] * dp[row - 1][0][0], g[row][0] * dp[row - 1][0][1] };

        for (int col = 1; col < g[0].size(); ++col)
            dp[0][col] = { g[0][col] * dp[0][col - 1][0], g[0][col] * dp[0][col - 1][1] };

        for (int row = 1; row < g.size(); ++row)
            for (int col = 1; col < g[0].size(); ++col) {
                dp[row][col][0] = min(min(g[row][col] * dp[row - 1][col][0], g[row][col] * dp[row][col - 1][0]),
                                      min(g[row][col] * dp[row - 1][col][1], g[row][col] * dp[row][col - 1][1]));
                dp[row][col][1] = max(max(g[row][col] * dp[row - 1][col][0], g[row][col] * dp[row][col - 1][0]),
                                      max(g[row][col] * dp[row - 1][col][1], g[row][col] * dp[row][col - 1][1]));
            }

        return dp.back().back().at(1) < 0 ? -1 : dp.back().back().at(1) % (int)(1e9 + 7);
    }
};