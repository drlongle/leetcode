/*
The solution first tests how many islands are there.

-> If there is a single island, it resets every set bit and tests if resetting the bit disconnects the island.
It it disconnects the single island into 2 or more islands OR removes a single bit island so that there are no
islands left, we return "one day" as answer.

-> If none of the bits tested could disconnect the single island, then we deduce that at least 2 bits are needed to do
the job. It is provable that 2 bits can disconnect any island in any configuration. So, we return "2 days" as answer.

-> If in the first test, we find no islands or there are already disconnected islands, we simply return "0 days" as answer.
 */

class Solution {
public:
    int dir[4][2] = { {-1, 0}, { 1, 0}, { 0, -1}, { 0, 1} };
    /* Accumulate adjacent ones to form an island */
    void dfs(vector<vector<int>>& g, int r, int c, vector<vector<bool>>& v, int rsz, int csz)
    {
        v[r][c] = true;
        for (auto d : dir) {
            int x = r + d[0], y = c + d[1];
            if ((x >= 0 && x < rsz) && (y >= 0 && y < csz) && (g[x][y] && !v[x][y]) )
                dfs(g, x, y, v, rsz, csz);
        }
    }
    /* Count islands */
    int ci(vector<vector<int>>& g, int rsz, int csz) {
        int ic = 0; vector<vector<bool>> v(rsz, vector<bool>(csz, 0));
        for (int i = 0; i < rsz; i++) {
            for (int j = 0; j < csz; j++) {
                if (g[i][j] && !v[i][j]) { dfs(g, i, j, v, rsz, csz); ++ic; }
            }
        }
        return ic;
    }
    int minDays(vector<vector<int>>& g) {
        int single = 0, rsz = g.size(), csz = g[0].size();
        for (int i = 0; i < rsz; i++) {
            for (int j = 0; j < csz; j++) {
                if (g[i][j]) {
                    if (!single && ci(g, rsz, csz) == 1) single++; /* found a single island */
                    if (single) {       /* if so, reset every set bit and test if resetting */
                        g[i][j] = 0;    /* ... a bit might disconnect the island */
                        int r = ci(g, rsz, csz);
                        if (r >= 2 /* disconnected */ || !r /* no island left */)
                            return 1 /* one day */;
                        g[i][j] = 1;
                    } else return 0; /* no islands or already disconnected - zero days */
                }
            }
        }
        return 2; /* two days */
    }
};
