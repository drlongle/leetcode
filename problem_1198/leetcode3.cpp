class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> pos(n);
        for (int j = 0; j < m; ++j) {
            bool found = true;
            for (int i = 1; i < n && found; ++i) {
                pos[i] = lower_bound(begin(mat[i]) + pos[i], end(mat[i]), mat[0][j]) - begin(mat[i]);
                if (pos[i] >= m) {
                    return -1;
                }
                found = mat[i][pos[i]] == mat[0][j];
            }
            if (found) {
                return mat[0][j];
            }
        }
        return -1;
    }
};