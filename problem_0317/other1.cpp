class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n < 0) return 0;
        int m = grid[0].size();

        vector<vector<int>>reached(n, vector<int>(m, 0));
        vector<vector<int>>distance(n, vector<int>(m, 0));

        int nofbuild = 0;
        int res = INT_MAX;


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    nofbuild ++;
                    bfs(grid, i, j, reached, distance);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(reached[i][j] == nofbuild && distance[i][j] < res)
                {
                    res = distance[i][j];
                }
            }
        }

        return res == INT_MAX? -1 : res;
    }

    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& reached, vector<vector<int>>& distance)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<int,int>>q;

        q.push({i, j});
        int level = 0;
        while(!q.empty())
        {
            level ++;
            int qs = q.size();
            for(int l = 0; l < qs; l++)
            {
                pair<int,int>cur = q.front();
                q.pop();

                for(int k = 0; k < 4; k++)
                {
                    int ni = cur.first + dir[k][0];
                    int nj = cur.second + dir[k][1];
                    if(ni < 0 || nj < 0 || ni >= n || nj >= m || visited[ni][nj] == 1 || grid[ni][nj] != 0)
                    {
                        continue;
                    }

                    q.push({ni, nj});
                    visited[ni][nj] = 1;
                    reached[ni][nj] ++;
                    distance[ni][nj] += level;
                }
            }
        }
    }
private:
    int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
};
