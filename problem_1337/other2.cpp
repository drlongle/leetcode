class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& M, int K) {
        int y = M.size(), x = M[0].size(), kix = 0;
        vector<int> vis(y), ans(K);
        for (int j = 0; j <= x; j++)
            for (int i = 0; i < y; i++) {
                if (!vis[i] && (j == x || !M[i][j])) {
                    ans[kix++] = i;
                    vis[i]++;
                }
                if (kix == K) return ans;
            }
        return ans;
    }
};
