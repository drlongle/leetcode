class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int ans = A.back() - A[0];
        for(int i=0;i<A.size()-1;i++)
        {
            int maxv = max(A[i]+K, A.back() - K);
            int minv = min(A[0]+K, A[i+1]-K);
            ans = min(ans, maxv - minv);
        }

        return ans;
    }
};
