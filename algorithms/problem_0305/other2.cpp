class Solution {
public:
    vector<int> uf;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int islands;

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        uf.assign(m*n, 0);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                uf[i*n + j] = i*n + j;
            }
        }

        islands = 0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> ans;
        int x, y;

        for (int k = 0; k < positions.size(); ++k){
            int i = positions[k][0], j = positions[k][1];
            if (grid[i][j] == 0){
                grid[i][j] = 1;
                islands++;
            }
            for (int d = 0; d < 4; ++d){
                x = i + dx[d], y = j + dy[d];
                if (0 <= x and x < m and 0 <= y and y < n and grid[x][y] == 1){
                    Union(i*n + j, x*n + y);
                }
            }
            ans.push_back(islands);
        }
        return ans;
    }

    int Find(int x){
        while (x != uf[x]){
            uf[x] = uf[uf[x]];
            x = uf[x];
        }
        return x;
    }

    void Union(int x, int y){
        int rootx = Find(x), rooty = Find(y);
        if (rootx == rooty) return;
        if (rootx > rooty){
            swap(x, y), swap(rootx, rooty);
        }
        uf[rooty] = rootx;
        islands--;
    }
};
