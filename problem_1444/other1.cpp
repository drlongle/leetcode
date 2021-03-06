class Solution {
#define mod (int)(1e9 + 7);
    int dp[55][55][15];
public:
    vector<vector<int>> pref;
    int n, m;

    int ways(vector<string> &pizza, int k) {
        memset(dp, -1, sizeof(dp));
        n = pizza.size(), m = pizza[0].size();

        pref.resize(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');

        return helper(k);
    }

    int helper(int k, int r = 1, int c = 1) {
        int oFact = pref[r - 1][m] + pref[n][c - 1] - pref[r - 1][c - 1];
        if (k == 1) return pref[n][m] - oFact != 0;
        if (r > n and c > m) return 0;
        if (dp[r][c][k] != -1) return dp[r][c][k];

        int ans = 0;
        for (int i = r; i <= n; i++) {
            int oFact = pref[r - 1][m] + pref[i][c - 1] - pref[r - 1][c - 1];
            if (pref[i][m] - oFact) ans += helper(k - 1, i + 1, c) % mod;
            ans %= mod;
        }

        for (int i = c; i <= m; i++) {
            int oFact = pref[n][c - 1] + pref[r - 1][i] - pref[r - 1][c - 1];
            if (pref[n][i] - oFact) ans += helper(k - 1, r, i + 1) % mod;
            ans %= mod;
        }

        return dp[r][c][k] = ans % mod;
    }
};
