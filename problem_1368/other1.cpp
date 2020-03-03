/*
Intuition
One observation is that, (not sure if it's obvious)
we can greedily explore the grid.
We will never detour the path to a node that we can already reach.

In the view of graph,
the fleche indicates a directed edge of weight = 0.
The distance between all neighbours are at most 1.
Now we want to find out the minimum distance between top-left and bottom-right.

Explanation
Find out all reachable nodes without changing anything.
Save all new visited nodes to a queue bfs.
Now iterate the queue
3.1 For each node, try changing it to all 3 other direction
3.2 Save the new reachable and not visited nodes to the queue.
3.3 repeat step 3

Complexity
Time O(NM)
Space O(NM)
 */

class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cost = 0;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        dfs(grid, 0, 0, dp, cost, q);
        while (!q.empty()) {
            cost++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                int r = p.first, c = p.second;
                q.pop();
                for (int j = 0; j < 4; j++)
                    dfs(grid, r + dir[j][0], c + dir[j][1], dp, cost, q);
            }
        }
        return dp[m - 1][n - 1];
    }
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp, int cost, queue<pair<int, int>>& q) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || dp[r][c] != INT_MAX) return;
        dp[r][c] = cost;
        q.push(make_pair(r, c));
        int nextDir = grid[r][c] - 1;
        dfs(grid, r + dir[nextDir][0], c + dir[nextDir][1], dp, cost, q);
    }
};
