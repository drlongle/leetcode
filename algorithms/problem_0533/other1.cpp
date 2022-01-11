class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        // To reduce the # of operations, we can calculate the # of blacks on each row and each column.
        // Also for each column contains 'B', we need to store the corresponding rows for comparison later.
        // We go through each element in the picture, for each 'B' at a column, we can find all rows from
        // the stored data and verify if they are equal to the current row.
        int rows = picture.size(), cols = picture[0].size(), res = 0;
        vector<int> rowBlackNum(rows, false), colBlackNum(cols, false);
        vector<vector<int>> rowHasBlack(cols); // store the rows for each column with a black

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (picture[i][j] == 'B') // find a black in current cell
                    {
                    ++rowBlackNum[i]; // this row has 1 more black
                    ++colBlackNum[j]; // this column has 1 more black
                    rowHasBlack[j].push_back(i); // ith row has black in jth column
                    }
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j) // go through each cell
                {
                if (picture[i][j] == 'B' && rowBlackNum[i] == N && colBlackNum[j] == N) // satisfy condition #1
                    {
                    int k = 0;
                    const auto& v = rowHasBlack[j]; // get all rows having black at column j
                    while (k < v.size() && picture[v[k]] == picture[i])
                    {
                        ++k; // check if each row is equal to the ith row
                    }

                    res += k >= v.size() ? 1 : 0; // update the result
                    }
                }
        }

        return res;
    }
};
