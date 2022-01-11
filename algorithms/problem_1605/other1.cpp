/*
Intuition
The greedy pick won't break anything, so just take as much as possible.

Explanation
For each result value at A[i][j], we greedily take the min(row[i], col[j]).

Then we update the row sum and col sum:
row[i] -= A[i][j]
col[j] -= A[i][j]

Easy Prove
A[i][j] will clear either row[i] or col[j],
that means either row[i] == 0 and col[j] == 0 in the end.

"It's guaranteed that at least one matrix that fulfills the requirements exists."
Also sum(row) == sum(col) always valid.

In the end, if row[i] > 0 and col[j] > 0,
then A[i][j] clear neither of them, based on 1) that's impossible.

So either sum(row) == 0 or sum(col) == 0.
Based on 2), we can have that sum(row) == sum(col) == 0.
That mean we find a right answer.
 */

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int m = row.size(), n = col.size();
        vector<vector<int>> A(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                A[i][j] = min(row[i], col[j]);
                row[i] -= A[i][j];
                col[j] -= A[i][j];
            }
        }
        return A;
    }
};