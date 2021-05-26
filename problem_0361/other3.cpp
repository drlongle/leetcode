class Solution {
public:
    int pre[502][502][2], suf[502][502][2];

    int maxKilledEnemies(vector <vector<char>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 'W') {
                    pre[i][j][0] = 0;
                    pre[i][j][1] = 0;
                } else if (grid[i][j] == 'E') {
                    if (j == 0) {
                        pre[i][j][0] = 1;
                    } else pre[i][j][0] = 1 + pre[i][j - 1][0];

                    if (i == 0) {
                        pre[i][j][1] = 1;
                    } else pre[i][j][1] = 1 + pre[i - 1][j][1];
                } else {
                    if (j > 0) pre[i][j][0] = pre[i][j - 1][0];
                    if (i > 0) pre[i][j][1] = pre[i - 1][j][1];
                }
            }
        }

        int ans = 0;
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    suf[i][j][0] = 0;
                    suf[i][j][1] = 0;
                } else if (grid[i][j] == 'E') {
                    if (j == grid[i].size() - 1) {
                        suf[i][j][0] = 1;
                    } else suf[i][j][0] = 1 + suf[i][j + 1][0];

                    if (i == grid.size() - 1) {
                        suf[i][j][1] = 1;
                    } else suf[i][j][1] = 1 + suf[i + 1][j][1];
                } else {
                    if (j < grid[i].size() - 1) suf[i][j][0] = suf[i][j + 1][0];
                    if (i < grid.size() - 1) suf[i][j][1] = suf[i + 1][j][1];
                }
                if (grid[i][j] == '0') {
                    int cur = pre[i][j][0] + suf[i][j][0] + pre[i][j][1] + suf[i][j][1];
                    ans = max(cur, ans);
                }
            }
        }

        return ans;
    }
};
