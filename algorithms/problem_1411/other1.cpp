class Solution {
public:
    int numOfWays(int n) {
        vector<vector<long>> res = {{6, 6}}, M = {{3, 2}, {2, 2}};
        for (--n; n; n >>= 1, M = mul(M, M))
            if (n % 2)
                res = mul(res, M);
        return (res[0][0] + res[0][1]) % ((int)1e9 + 7);
    }

    // Matrix multiplication
    vector<vector<long>> mul(vector<vector<long>> &A, vector<vector<long>> &B) {
        int n = A.size(), l = B.size(), m = B[0].size(), mod = 1e9 + 7;
        vector<vector<long>> C(n, vector<long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < l; ++k)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
        return C;
    }
};
