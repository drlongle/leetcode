class Solution {
public:
    long long res;
    bool hasZero;
    int m, n;
    int maxProductPath(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }
        hasZero = false;
        res = INT_MIN;
        m = grid.size(); n = grid[0].size();
        dfs(grid, 0,0, 1);
        if (hasZero) {
            return res < 0 ? 0 : (res % 1000000007);
        }
        return res < 0 ? -1 : (res % 1000000007);
    }
    void dfs(vector<vector<int>>& grid, int i, int j, long long curr) {
        if (i < 0 || i >= m || j < 0 || j >= n ) {
            return;
        }
        if (grid[i][j] == 0) {
            hasZero = true;
            return;
        }
        if (i == m - 1 && j == n - 1) {
            curr *= grid[i][j];
            res = max(res, curr);
            return;
        }

        curr *= grid[i][j];
        dfs(grid, i+1, j, curr);
        dfs(grid, i, j+1, curr);
    }
};
