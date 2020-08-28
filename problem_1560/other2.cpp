/*
Intuition
We only need to care the start point and the end point.

                s ----- n
1 --------------------- n
1 --------------------- n
1 ----- e

Explanation
If start <= end, return the range [start, end].
If end < start, return the range [1, end] + range [start, n].
*/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& A) {
        vector<int> res;
        for (int i = A[0]; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        if (res.size() > 0) return res;
        for (int i = 1; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        for (int i = A[0]; i <= n; ++i)
            res.push_back(i);
        return res;
    }
};