class Solution {
public:
    void dfs(string &path, int i, int j, vector<vector<int>> &grid) {
        if(i + 1 < grid.size() && grid[i + 1][j]) {
            grid[i + 1][j] = 0;
            path += 'd';
            dfs(path, i + 1, j, grid);
        }
        path += "-";
        if(i - 1 >= 0 && grid[i - 1][j]) {
            grid[i - 1][j] = 0;
            path += 'u';
            dfs(path, i - 1, j, grid);
        }
        path += "-";
        if(j + 1 < grid[0].size() && grid[i][j + 1]) {
            grid[i][j + 1] = 0;
            path += 'r';
            dfs(path, i, j + 1, grid);
        }
        path += "-";
        if(j - 1 >= 0 && grid[i][j - 1]) {
            grid[i][j - 1] = 0;
            path += 'l';
            dfs(path, i, j - 1, grid);
        }
        path += "-";
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> s;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    string path = "";
                    grid[i][j] = 0;
                    dfs(path, i, j, grid);
                    //cout << path << endl;
                    s.insert(path);
                }
            }
        }
        return s.size();
    }
};
