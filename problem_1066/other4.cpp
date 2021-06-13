class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int m;
    int total;
    int getd(vector<int>& w, vector<int>& b)
    {
        return abs(w[0] - b[0]) + abs(w[1] - b[1]);
    }
    int dfs(int i, int bm, vector<vector<int>>& workers, vector<vector<int>>& bikes)
    {
        if (i >= n) return 0;
        if (dp[i][bm] != INT_MAX)
        {
            return dp[i][bm];
        }
        vector<int>& w = workers[i];
        int cur = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            int bit = (1 << j);
            if ((bit & bm) == bit)
            {
                continue;
            }
            int d = getd(w, bikes[j]);
            int next = dfs(i + 1, (bm | bit), workers, bikes);
            cur = min(cur, d + next);
        }
        dp[i][bm] = cur;
        return cur;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n = workers.size();
        m = bikes.size();
        total = 1 << m;
        dp = vector<vector<int>>(n, vector<int>(total, INT_MAX));
        int res = dfs(0, 0, workers, bikes);
        return res;
    }
};
