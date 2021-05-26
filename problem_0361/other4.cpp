// count enemies at each point on each row and col, using 2 pointer technique

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int R = grid.size(); if (R == 0) return 0;
        int C = grid[0].size();

        vector<vector<int>> rows(R, vector<int> (C, 0)), cols(R, vector<int> (C, 0));

        for (int r = 0; r < R; r ++) {
            int l1 = 0, r1 = 0, count = 0;
            while (r1 < C) {
                count = 0;
                l1 = r1;
                while (r1 < C && grid[r][r1] != 'W') {
                    if (grid[r][r1] == 'E') count ++;
                    r1 ++;
                }
                for (; l1 <r1; l1 ++) {
                    rows[r][l1] = count;
                }
                r1 ++;
            }
        }

        for (int c = 0; c < C; c ++) {
            int u1 = 0, d1 = 0, count = 0;
            while (d1 < R) {
                count = 0;
                u1 = d1;
                while (d1 < R && grid[d1][c] != 'W') {
                    if (grid[d1][c] == 'E') count ++;
                    d1 ++;
                }
                for (; u1 < d1; u1 ++) {
                    cols[u1][c] = count;
                }
                d1 ++;
            }
        }

        int maxres = 0;
        for (int r = 0; r < R; r ++) {
            for (int c = 0; c < C; c ++) {
                if (grid[r][c] == '0')
                    maxres = max(maxres, rows[r][c] + cols[r][c]);
            }
        }

        return maxres;
    }
};
