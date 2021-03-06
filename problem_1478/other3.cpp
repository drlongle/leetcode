class Solution
{
public:
    int dp[101][101] = {};
    int dfs(vector<int> &h, vector<vector<int>> &costs, int i, int k)
    {
        if (i >= h.size() || k <= 0)
            return i == h.size() && k == 0 ? 0 : 10000000;
        if (!dp[i][k])
        {
            dp[i][k] = 10000000;
            for (auto j = i; j <= h.size() - k; ++j)
                dp[i][k] = min(dp[i][k], costs[i][j] + dfs(h, costs, j + 1, k - 1));
        }
        return dp[i][k];
    }
    int minDistance(vector<int> &h, int k)
    {
        sort(begin(h), end(h));
        vector<vector<int>> costs(h.size(), vector<int>(h.size()));
        for (auto i = 0; i < h.size(); ++i)
        {
            for (auto j = i; j < h.size(); ++j)
            {
                int mbold = h[(i + j - 1) / 2], mbnew = h[(i + j) / 2];
                costs[i][j] = (j == 0 ? 0 : costs[i][j - 1]) +
                              h[j] - mbnew + (mbnew - mbold) * (j - i) % 2;
            }
        }
        return dfs(h, costs, 0, k);
    }
};