/*
Assume the final result is k,
And there are m number not missing in the range of [1, k].
Binary search the m in range [0, A.size()].

If there are m number not missing,
that is A[0], A[1] .. A[m-1],
the number of missing under A[m-1] is A[m-1] - m.

If A[m - 1] - m < k, m is small enough.
If A[m - 1] - m >= k, m is too big.
 */

class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r + 1) / 2;
            if (m == 0 || A[m - 1] - m < k)
                l = m;
            else
                r = m - 1;
        }
        return l + k;
    }
};