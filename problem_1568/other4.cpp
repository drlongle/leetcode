class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0,1}};
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>* points = NULL)
    {
        int count = 0;
        vector<int> dir(4);
        for (int i = 0; i < directions.size(); i++)
        {
            int r = row + directions[i][0];
            int c = col + directions[i][1];

            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c])
            {
                dir[i] = 1;
                ++count;
                if (grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    dfs(grid, r, c, points);
                }
            }
        }

        if(points)
        {
            if (count == 0 || (count == 2 && ((dir[0] & dir[1]) ^ (dir[2] & dir[3]))))
                points->push_back({row, col});
            else if(count == 1)
            {
                for(int i = 0; i < dir.size(); i++)
                {
                    if(dir[i])
                    {
                        points->push_back({row + directions[i][0], col + directions[i][1]});
                        break;
                    }
                }
            }
        }
    }

    int islandCount(vector<vector<int>> grid, vector<vector<int>>* points = NULL)
    {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    cnt++;
                    dfs(grid, i, j, points);
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid)
    {
        vector<vector<int>> points;

        int cnt = islandCount(grid, &points);
        if(cnt > 1 || cnt == 0)
            return 0;

        for(int i = 0; i < points.size(); i++)
        {
            grid[points[i][0]][points[i][1]] = 0;
            int cnt = islandCount(grid);
            if(cnt > 1 || cnt == 0)
                return 1;
            grid[points[i][0]][points[i][1]] = 1;
        }
        return 2;
    }
};
