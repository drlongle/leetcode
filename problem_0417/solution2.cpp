class Solution {
public:
    void visit(vector<vector<int>>& matrix, queue<tuple<int, int, int>>& q, int val) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> offsets{{1,0}, {-1, 0}, {0,1}, {0,-1}};
        while (q.size()) {
            auto& e = q.front();
            int i = get<0>(e), j = get<1>(e), h = get<2>(e);
            q.pop();
            for (auto& offset: offsets) {
                int ni = i + offset[0], nj = j + offset[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (matrix[ni][nj] >= h && ((vals[ni][nj] & val) == 0)) {
                        vals[ni][nj] |= val;
                        q.emplace(ni, nj, matrix[ni][nj]);
                    }
                }
            }
        }
    }

    vector<vector<int>> vals;
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        m = matrix.size();
        if (!m)
            return res;
        n = matrix[0].size();
        if (!n)
            return res;
        vals.resize(m, vector<int>(n, 0));

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(0, i, matrix[0][i]);
            vals[0][i] |= 1;
        }
        for (int i = 0; i < m; ++i) {
            q.emplace(i, 0, matrix[i][0]);
            vals[i][0] |= 1;
        }
        visit(matrix, q, 1);

        for (int i = 0; i < n; ++i) {
            q.emplace(m-1, i, matrix[m-1][i]);
            vals[m-1][i] |= 2;
        }
        for (int i = 0; i < m; ++i) {
            q.emplace(i, n-1, matrix[i][n-1]);
            vals[i][n-1] |= 2;
        }
        visit(matrix, q, 2);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vals[i][j] == 3)
                    res.emplace_back(vector<int>{i, j});
            }
        }

        return res;
    }
};