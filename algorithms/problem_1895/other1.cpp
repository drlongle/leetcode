class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> rows(m + 2, vector<int>(n + 2)), cols(rows);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
                cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
            }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = min(m - i, n - j); k > res; --k) {
                    int sum = rows[i][j + k] - rows[i][j - 1], l = 0, d1 = 0, d2 = 0;
                    for (; l <= k; ++l) {
                        if (sum != rows[i + l][j + k] - rows[i + l][j - 1]
                            || sum != cols[i + k][j + l] - cols[i - 1][j + l])
                            break;
                        d1 += grid[i - 1 + l][j - 1 + l];
                        d2 += grid[i - 1 + k - l][j - 1 + l];
                    }
                    res = l > k && d1 == sum && d2 == sum ? k : res;
                }
        return res + 1;
    }
};
