/*
For each row, check if the row is the same (or XOR of the row is the same) as the first row. If the row is different, add it to m1.
In the end, the number of same rows is m.size() - m1.size(). Track and return the maximum of that value.
Repeat this for the remaining rows (collected in m1) until there are no more rows.
*/

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &m, size_t res = 0)
    {
        while (m.size() > res)
        {
            vector<vector<int>> m1;
            for (auto i = 1, j = 0; i < m.size(); ++i)
            {
                for (j = 0; j < m[i].size() && m[0][0] ^ m[i][0] == m[0][j] ^ m[i][j]; ++j)
                    ;
                if (j != m[i].size())
                    m1.push_back(m[i]);
            }
            res = max(res, m.size() - m1.size());
            m = m1;
        }
        return res;
    }
};