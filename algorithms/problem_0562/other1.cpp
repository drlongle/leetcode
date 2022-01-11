class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> h(m, 0);
        vector<int> v(n, 0);
        vector<int> d(m + n - 1, 0);
        vector<int> ad(m + n - 1, 0);
        /*
        (2,0)
        (1,0) (2,1)
        (0,0) (1,1) (2,2)
        (0,1) (1,2) (2,3)

        (0,0)
        (0,1) (1,0)
        (0,2) (1,1) ()
        */
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    ans = max(ans, ++h[i]);
                    ans = max(ans, ++v[j]);
                    ans = max(ans, ++d[j - i + m - 1]);
                    ans = max(ans, ++ad[i + j]);
                } else {
                    h[i] = v[j] = d[j - i + m - 1] = ad[i + j] = 0;
                }
            }
        }
        return ans;
    }
};
