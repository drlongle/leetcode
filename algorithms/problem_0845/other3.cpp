class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int N = A.size();
        vector<int> ups(N, 0), downs(N, 0);
        for(int i = 1; i < N; i++) if(A[i] > A[i-1]) ups[i] = ups[i-1]+1;
        int ans = 0;
        for(int i = N - 1; i >= 0; i--){
            if(i < N - 1 && A[i] > A[i+1]) downs[i] = downs[i+1]+1;
            if(ups[i] && downs[i]) ans = max(ans, ups[i] + downs[i] + 1);
        }
        return ans;
    }
};
