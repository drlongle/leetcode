class Solution {
public:
    int maxProfit(const vector<int>& p) {
        int res = 0;
        for (int i = 1; i < size(p); ++i) {
            res += max(0, p[i] - p[i - 1]);
        }
        return res;
    }

    int maxProfit(int k, const vector<int>& p) {
        constexpr int INF = 10000000;
        const int n = size(p);
        if (k == 0) return 0;
        if (2 * k >= n) return maxProfit(p);
        int dp[n][k + 1][2];
        memset(dp, -INF, sizeof(int) * n * (k + 1) * 2);
        dp[0][0][0] = 0;
        dp[0][1][1] = -p[0];
        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= k; ++t) {
                dp[i][t][0] = max(dp[i - 1][t][0], dp[i - 1][t][1] + p[i]);
                dp[i][t][1] = max(dp[i - 1][t][1], t > 0 ? dp[i - 1][t - 1][0] - p[i] : -INF);
            }
        }
        int res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, dp[n - 1][i][0]);
        }
        return res;
    }
};