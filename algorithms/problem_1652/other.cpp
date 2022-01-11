
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> Sum(code), ans(N);
        for(int i=1; i<N; ++i)
            Sum[i] = Sum[i-1] + code[i];
        for(int i=0; i<N; ++i) {
            int start = (i + N + (k < 0 ? k - 1 : 0)) % N;
            int end = (i + N + (k > 0 ? k : -1)) % N;
            if(!k) ans[i] = 0;
            else if(start < end) ans[i] = Sum[end] - Sum[start];
            else                 ans[i] = Sum[end] + (Sum[N-1] - Sum[start]);
        }
        return ans;
    }
};
