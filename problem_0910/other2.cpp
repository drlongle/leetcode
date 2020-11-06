class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        for (auto & a : A) a -= K;
        sort(A.begin(), A.end());
        multiset<int> S;
        int n = A.size();
        int maxNum = A[n-1];
        int ans = maxNum - A[0];
        for (auto & a : A) S.insert(a);
        K *= 2;
        int i = 0;
        while (i < n-1) {
            S.erase(S.find(A[i]));
            A[i] += K;
            S.insert(A[i]);
            maxNum = max(maxNum, A[i]);
            ans = min(ans, maxNum - *S.begin());
            i++;
        }
        return ans;
    }
};
