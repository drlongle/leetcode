class Solution {

    // Expand in one direction (up, down, left or right). Keep going until we hit a wall.
    int dfs(vector<vector<char>>& grid, int i, int j, int x, int y, int m, int n) {
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 'W') return 0;

        int ans = grid[i][j] == 'E' ? 1 : 0;
        ans += dfs(grid, i+x, j+y, x, y, m, n);
        return ans;
    }
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<int>dir = {-1, 0, 1, 0, -1};
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    int ans = 0;
                    for (int k = 1; k < dir.size(); k++)
                        ans += dfs(grid, i, j, dir[k], dir[k-1], m, n);
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};
