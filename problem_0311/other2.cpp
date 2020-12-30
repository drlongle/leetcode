class Solution {
public:
    using vector_compress = unordered_map<int, unordered_map<int, int>>;

    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {

        vector_compress A_map;
        vector_compress B_map;

        for (int row = 0; row < A.size(); ++row) {
            for (int col = 0; col < A[0].size(); ++col) {
                if (A[row][col]) {
                    A_map[row][col] = A[row][col];
                }
            }
        }

        for (int row = 0; row < B.size(); ++row) {
            for (int col = 0; col < B[0].size(); ++col) {
                if (B[row][col]) {
                    B_map[col][row] = B[row][col];
                }
            }
        }

        return multiply_compress(A_map, B_map, A.size(), B[0].size(), B.size());
    }

    vector<vector<int>> multiply_compress(vector_compress& A, vector_compress& B, int rows, int cols, int line)
    {
        vector<vector<int>> C(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; ++row) {

            if (!A.count(row)) {
                continue;
            }

            for (int col = 0; col < cols; ++col) {

                if (!B.count(col)) {
                    continue;
                }

                for (int i = 0; i < line; ++i) {
                    if (A[row].count(i) && B[col].count(i)) {
                        C[row][col] += A[row][i] * B[col][i];
                    }
                }
            }
        }

        return C;
    }
};
