class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty())
        {
            return 0;
        }

        int rows = M.size(), cols = M[0].size(), res = 0;
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(4, 0)));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (M[i][j] == 1)
                {
                    dp[i][j][0] = (j > 0 ? dp[i][j - 1][0] : 0) + 1;
                    dp[i][j][1] = (i > 0 ? dp[i - 1][j][1] : 0) + 1;
                    dp[i][j][2] = (i > 0 && j > 0 ? dp[i - 1][j - 1][2] : 0) + 1;
                    dp[i][j][3] = (i > 0 && j + 1 < cols ? dp[i - 1][j + 1][3] : 0) + 1;

                    for (int k = 0; k < 4; ++k)
                    {
                        res = max(res, dp[i][j][k]);
                    }
                }
            }
        }

        return res;
    }
};
