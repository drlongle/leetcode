class Solution {
public:
    int find(vector<int> &r, int i) {
        while(i!=r[i]) i=r[i]=r[r[i]];
        return i;
    }
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> r(N);
        int i, c=N;
        for(i=0; i<N; i++) r[i]=i;
        sort(logs.begin(), logs.end());
        for(auto &l:logs) {
            int u=find(r, l[1]), v=find(r, l[2]);
            if (u==v) continue;
            r[v]=u;
            c--;
            if (c==1) return l[0];
        }
        return -1;
    }
};
