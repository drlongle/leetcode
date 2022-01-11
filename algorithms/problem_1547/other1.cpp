/*
Similar problems:

312. Burst Balloons
1000. Minimum Cost to Merge Stones
1039. Minimum Score Triangulation of Polygon

To make it simpler, we add two sentinel values to cuts - left and right edges of the stick.
Then, we sort the cuts so we can easily identify all cuts between two points.
DFS can help us find the most efficient sequence of cuts. To avoid recomputation, we memoise the
best answer for stick between cuts[i] and cuts[j] in dp[i][j].
 */

class Solution {
public:
    int dp[102][102] = {};
    int dfs(vector<int>& cuts, int i, int j) {
        if (j - i <= 1)
            return 0;
        if (!dp[i][j]) {
            dp[i][j] = INT_MAX;
            for (auto k = i + 1; k < j; ++k)
                dp[i][j] = min(dp[i][j],
                               cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        return dfs(cuts, 0, cuts.size() - 1);
    }
};