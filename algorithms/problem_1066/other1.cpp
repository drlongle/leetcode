// Dijkstria

class Solution {
public:
    int dist(vector<int> &a, vector<int> &b) {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int i, j, n=workers.size(), m=bikes.size(), mask=0x3ff, ret=INT_MAX;
        vector<vector<int>> D(n, vector<int>(1<<m, INT_MAX));
        auto cmp=[](auto &a, auto &b){return a[0]>b[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for(i==0; i<n; i++) D[i][0]=0;
        q.push({0, 0, 0});
        while(q.size()) {
            auto a=q.top();
            q.pop();
            int c=a[0], i=a[1], s=a[2];
            if (i==n) {
                ret=min(ret, c);
                continue;
            }
            for(j=0; j<m; j++) {
                if (s&(1<<j)) continue;
                int ns=(s|(1<<j)), nc=c+dist(workers[i], bikes[j]);
                if (nc>=D[i][ns]) continue;
                D[i][ns]=nc;
                q.push({nc, i+1, ns});
            }
        }
        return ret;
    }
};
