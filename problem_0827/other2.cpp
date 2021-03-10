class Solution {
public:
    int direct[5] = {1, 0, -1, 0, 1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), id = 2, res = 0;
        vector<int> size(2);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int nums = 0;
                    dfs(grid, id++, i, j, nums);
                    size.push_back(nums);
                    res = max(res, nums);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st;
                    for(int k = 0; k < 4; k++) {
                        int x = direct[k] + i;
                        int y = direct[k + 1] + j;
                        if(x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] == 0)
                            continue;
                        st.insert(grid[x][y]);
                    }
                    int cur = 1;
                    for(auto val : st) cur += size[val];
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int id, int i, int j, int& nums) {
        nums++;
        grid[i][j] = id;
        for(int k = 0; k < 4; k++) {
            int x = direct[k] + i;
            int y = direct[k + 1] + j;
            if(x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] == 0 || grid[x][y] > 1)
                continue;
            dfs(grid, id, x, y, nums);
        }
    }
};
