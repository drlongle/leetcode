class Solution {
public:
    int metaSearch(vector<int> &row, int pos, int val, int d = 1) {
        int sz = row.size();
        while (pos < sz && row[pos] < val) {
            d <<= 1;
            if (row[min(pos + d, sz - 1)] >= val) {
                d = 1;
            }
            pos += d;
        }
        return pos;
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int cur_max = 0, cnt = 0;
        vector<int> pos(n);
        while (true) {
            for (int i = 0; i < n; ++i) {
                pos[i] = metaSearch(mat[i], pos[i], cur_max);
                if (pos[i] >= m) {
                    return -1;
                }
                if (cur_max != mat[i][pos[i]]) {
                    cnt = 1;
                    cur_max = mat[i][pos[i]];
                } else if (++cnt == n) {
                    return cur_max;
                }
            }
        }
        return -1;
    }
};