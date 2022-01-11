class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        // Use a set of vectors to store the unique shape of islands. We can treat the grid as 1-D array
        // and add the index of each 1 in an island into the set. Also, we make the 1st element of each
        // vector to be 0. By doing this, once we find an island, we can get the indices of each 1 in this
        // island (1st element 0) and check if it exists in the set already. If yes ignore it, otherwise
        // add it to the set. Finally we can return the size of the set.
        set<vector<int>> islands;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    vector<int> island = dfs(grid, i, j);
                    int diff = island[0];
                    for (int k = 0; k < island.size(); ++k)
                    {
                        island[k] -= diff;
                    }

                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }

private:
    vector<int> dfs(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
        {
            return {};
        }

        vector<int> res{row * (int)grid[0].size() + col};
        grid[row][col] = -1;
        vector<int> right = dfs(grid, row, col + 1), down = dfs(grid, row + 1, col);
        vector<int> up = dfs(grid, row - 1, col), left = dfs(grid, row, col - 1);

        res.insert(res.end(), right.begin(), right.end());
        res.insert(res.end(), down.begin(), down.end());
        res.insert(res.end(), up.begin(), up.end());
        res.insert(res.end(), left.begin(), left.end());
        return res;
    }
};
