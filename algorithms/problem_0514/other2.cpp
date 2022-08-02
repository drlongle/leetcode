class Solution {
  public:
    int dfs(string ring, string key, int r, int k, vector<vector<int>> &dp) {

        if (k == key.size())
            return 0;
        if (dp[r][k] != -1)
            return dp[r][k];
        int res = INT_MAX;
        for (int i = 0; i < ring.size(); i++) {
            if (ring[i] == key[k]) {
                int x = abs(i - r);
                int y = ring.size() - x;
                int dis = min(x, y);
                res = min(res, dis + 1 + dfs(ring, key, i, k + 1, dp));
            }
        }
        return dp[r][k] = res;
    }
    int findRotateSteps(string ring, string key) {

        vector<vector<int>> dp(ring.size(), vector<int>(key.size(), -1));
        // dp[i][j] means min steps when ith of ring is at the 12:00 position
        // and key is upto jth
        return dfs(ring, key, 0, 0, dp);
    }
};
