class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) continue;
                ++count;
                for (int d = 1; d < min(n - j, m - i); ++d) {
                    int x;
                    for (x = 0; x <= d; ++x)
                        if (matrix[i + d][j + x] == 0 || matrix[i + x][j + d] == 0)
                            break;
                    if (x <= d) break;
                    ++count;
                }
            }
        }
        
        return count;
    }
};
