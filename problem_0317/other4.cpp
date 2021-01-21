class Solution {
    int R, C;
    int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return -1;
        R = grid.size(), C = grid[0].size();
        int building = 0;
        vector<vector<int>> dist(R, vector<int>(C, 0));
        vector<vector<int>> counter(R, vector<int>(C, 0));

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {
                    building++;
                    BFS(grid, r, c, dist, counter);
                }
            }
        }
        int res = INT_MAX;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (dist[r][c] > 0 && counter[r][c] == building) res = min(res, dist[r][c]);
            }
        }

        return res==INT_MAX?-1:res;
    }

    void BFS (vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dist,
              vector<vector<int>>& counter) {
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int,int>> Q;
        pair<int,int> P;
        Q.push({row, col});
        visited[row][col] = true;
        int distance = 1;
        while (!Q.empty()) {
            for (int cnt = Q.size(); cnt > 0; cnt--) {
                P = Q.front(); Q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = P.first + dirs[i][0], c = P.second + dirs[i][1];
                    if (r < 0 || r >= R || c < 0 || c >= C) continue;
                    if (visited[r][c] == true) continue;
                    if (grid[r][c] > 0) continue;
                    Q.push({r, c});
                    visited[r][c]= true;
                    dist[r][c] += distance;
                    counter[r][c]++;
                }
            }
            distance++;
        }
    }
};
