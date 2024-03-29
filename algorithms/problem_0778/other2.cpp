class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        priority_queue<pair<int, int> > pq;
        pq.emplace(-grid[0][0], 0*n+0);
        vector<int> seen(n*n,0);
        seen[0*n+0]=1;
        vector<int> dirs{-1,0,1,0,-1};
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            int t = -cur.first;
            int r = cur.second/n;
            int c = cur.second%n;
            if(r == n - 1 && c == n - 1) return t;
            for(int d = 0;  d < 4; d++){
                int nr = r + dirs[d];
                int nc = c + dirs[d+1];
                if(nr <0 || nr >= n || nc < 0 || nc >= n || seen[nr*n + nc] == 1) continue;
                seen[nr*n + nc] = 1;
                pq.emplace(-max(t, grid[nr][nc]), nr*n + nc);
            }
        }
        return n*n;
    }
};
