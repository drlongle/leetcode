/*
Intuition
We want to calculate the frequency for A[i].
Assign the big element A[i] to the position queried more frequently.

Explanation
For each request [i,j],
we set count[i]++ and count[j + 1]--,

Then we sweep once the whole count,
we can find the frequency for count[i].

Note that for all intervals inputs,
this method should be the first intuition you come up with.
*/

class Solution {
public:
    int maxSumRangeQuery(vector<int>& A, vector<vector<int>>& req) {
        int res = 0, mod = 1e9 + 7, n = A.size();
        vector<int> count(A.size());
        for (auto &r: req) {
            count[r[0]] += 1;
            if (r[1] + 1 < n)
                count[r[1] + 1] -= 1;
        }
        for (int i = 1; i < n; ++i)
            count[i] += count[i - 1];
        sort(begin(count), end(count));
        sort(begin(A), end(A));
        for (int i = 0; i < n; ++i)
            res = (res + A[i] * count[i]) % mod;
        return res;
    }
};