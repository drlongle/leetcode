class Solution {
public:
    int numberOfPatterns(int m, int n)
    {
        size_t output{ 0 }, length{ 0 };
        vector<vector<bool>> table(3, vector<bool>(3));
        backtrack(m, n, table, length, output, 9999, 9999);
        return output;
    }


    void backtrack(const size_t &m, const size_t &n, vector<vector<bool>> &visited, size_t length, size_t &output, int bef_i, int bef_j)
    {
        if(length >= m)
        {
            ++output;
            if(length == n) return;
        }

        for(int i{ 0 }; i < 3; ++i)
            for(int j{ 0 }; j < 3; ++j)
            {
                int col_diff{ abs((int)(i - bef_i)) }, row_diff{ abs((int)(j - bef_j)) };

                const bool &already_exist{ visited[i][j] };
                const bool &diagonal_without_middle{ col_diff == 2 && row_diff == 2 && !visited[1][1] };
                const bool &same_colum_without_middle{ col_diff == 2 && row_diff == 0 && !visited[1][j] };
                const bool &same_row_without_middle{ col_diff == 0 && row_diff == 2 && !visited[i][1] };

                if(already_exist || (diagonal_without_middle || same_colum_without_middle || same_row_without_middle )) continue;

                visited[i][j] = true;
                ++length;
                backtrack(m, n, visited, length, output, i, j);
                --length;
                visited[i][j] = false;
            }
    }
};
