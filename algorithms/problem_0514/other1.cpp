class Solution {
  public:
    /*
        f[i][j]: # of operations for outputing first i characters and pointer
       now is pointing to jth character on the ring.

        f[i][j] = f[i][k] + k->j (two possibles) + 1 (push button)
    */
    const int inf = 1e8;

    int findRotateSteps(string ring, string key) {
        const int n = ring.size(), m = key.size();
        ring = ' ' + ring, key = ' ' + key;
        vector<vector<int>> f(m + 1, vector<int>(n + 1, inf));
        f[0][1] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (ring[j] == key[i]) {
                    for (int k = 1; k <= n; k++) {
                        int t = abs(k - j);
                        f[i][j] = min(f[i][j], f[i - 1][k] + min(t, n - t) + 1);
                    }
                }
            }
        }

        int res = inf;
        for (int i = 1; i <= n; i++)
            res = min(res, f[m][i]);

        return res;
    }
};
