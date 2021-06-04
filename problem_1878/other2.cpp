class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int sz = 0; i - sz >= 0 && i + sz < m && j + 2 * sz < n; sz++) {
                    int cur = grid[i][j];
                    int x = i, y = j;
                    for (int cnt = 0; cnt < sz; cnt++)
                        cur += grid[--x][++y];
                    for (int cnt = 0; cnt < sz; cnt++)
                        cur += grid[++x][++y];
                    for (int cnt = 0; cnt < sz; cnt++)
                        cur += grid[++x][--y];
                    for (int cnt = 0; cnt < sz - 1; cnt++)
                        cur += grid[--x][--y];
                    res.insert(cur);
                    if (res.size() > 3)
                        res.erase(res.begin());
                }
            }
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};
