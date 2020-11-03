class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hs) {
        const int n = hs.size(), m = hs[0].size();
        const auto dirs = vector<pair<int,int>>{{0,1}, {0,-1},{-1,0},{1,0}};
        auto visited = vector(n, vector(m,false));
        priority_queue<tuple<int,int,int>> q; //{-h, i, j}
        q.push(tuple{0, 0, 0});
        while(!q.empty()){
            const auto [eff, i, j] = q.top(); q.pop();
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(i == n-1 && j == m-1) return -eff;
            for(auto [di, dj] : dirs){
                int x = i+di, y = j+dj;
                if(x<0 || x>=n || y<0 || y>=m || visited[x][y]) continue;
                auto eff1 = min(eff, -abs(hs[x][y] - hs[i][j]));
                q.push(tuple{eff1, x, y});
            }
        }
        return -1;
    }
};