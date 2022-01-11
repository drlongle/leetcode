/*
If the image is sparse matrix, we can save computation in the following way.

To make the problem simpler, think of two 1d arrays, we want to compute the largestOverlap of them. We can store the
indexes of 1s into two vector<int> va and vb, and compute the most common distance between va[i] and vb[j].

Example:

A = [1, 1, 1, 0]
B = [0, 1, 0, 1]
va = [0, 1, 2]
vb = [1, 3]
// we compute the difference between each pair of the indexes
diff = [-1, 0, 1,
        -3, -2, -1]
frequency = {
    {-3, 1},
    {-2, 1},
    {-1, 2}, // -1 appeared twice
    {0, 1},
    {1, 1}
}
// Since -1 is the most frequent difference and its frequency is 2
// The best answer is to shift `B` by `-1` and we get `2` overlaps.
For a 2d array, the distance becomes 2d as well. Instead of using pairs, we encode x, y as 100 * x + y thus the 2d array
is flattened to 1d array, and the distance becomes 100 * delta_x + delta_y. The most common distance is the answer.

Why using 100 instead of 30? Since the delta_y has range -29 = -(N - 1) to 29 = (N - 1). So using 30 will cause
ambiguous interpretation of the distance. For example, distance 15 can be interpreted as 0 * 30 + 15 and 1 * 30 - 15.

The minimum value of the multiplier is the size of range of delta_y which is (N - 1) - -(N - 1) + 1 = 2 * N - 1.
 */

class Solution {
private:
    vector<int> flatten(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) ans.push_back(i * 100 + j);
            }
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto va = flatten(A), vb = flatten(B);
        unordered_map<int, int> m;
        for (int i : va) {
            for (int j : vb) {
                m[i - j]++;
            }
        }
        int ans = 0;
        for (auto p : m) ans = max(ans, p.second);
        return ans;
    }
};
