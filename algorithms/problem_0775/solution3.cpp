class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 1, n = A.size(), maxn = 0; i < n; ++i) {
            if (A[i] < maxn)
                return false;
            maxn = max(maxn, A[i-1]);
        }
        return true;
    }
};