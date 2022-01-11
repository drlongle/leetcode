class Solution {
public:
    int maxSideLength(vector<vector<int>> A, int threshold) {
        int s = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                #define a(i, j) (i < 0 || j < 0 ? 0 : A[i][j])
                A[i][j] += a(i-1, j) + a(i, j-1) - a(i-1, j-1);
                s += s <= min(i, j) && a(i, j) - a(i-s-1, j) - a(i, j-s-1) + a(i-s-1, j-s-1) <= threshold;
            }
        }
        return s;
    }
};
