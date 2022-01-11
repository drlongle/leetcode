/*
Key idea:

- only considers the point with 1, so O(N1 * N2) where N1 and N2 are the number of points with 1 in each image
- Image A can be shifted horizontally in range [-M+1, M-1] and vertically in [-N+1, N-1],
  where + means right or down and - means left or up
- For each pair of points, update counter array of size 2M x 2N which keeps track of the number of
  overlapping points for the shift amount to overlap them where (M, N) is the origin.
 */

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // vector of pair<r, c> for 1
        int M = A.size(); // row count
        int N = A[0].size(); // column count
        vector<pair<int, int>> oneA, oneB;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j])
                    oneA.emplace_back(i, j);
                if (B[i][j])
                    oneB.emplace_back(i, j);
            }
        }

        vector<vector<int>> C(2*M, vector<int>(2*N, 0));
        // for each pair, compute the diff in offset <row shift ro, column shift co>
        // for convenience, (M, N) is the origin
        for (auto a : oneA) {
            for (auto b : oneB) {
                C[b.first + M - a.first][b.second + N - a.second]++;
            }
        }

        int maxCnt = 0;
        for (int i = 0; i < 2*M; i++) {
            for (int j = 0; j < 2*N; j++) {
                if (C[i][j] > maxCnt)
                    maxCnt = C[i][j];
            }
        }
        // return max
        return maxCnt;
    }
};
