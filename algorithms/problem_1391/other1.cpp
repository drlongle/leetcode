/*
Intuition
You do not need to search for a path. You just follow the existing path until you can, and check if you reach your destination.

The only variable here is your initial direction: e.g. if you start at a turn, you can go either down or right.

Solution
Let's define 4 directions: left (0), right (1), down (2) and up (3). Each road type can continue from some direction, and can change it to another direction.

For example, for road type 3, you can continue from left, and it changes your direction to down. Or, you can continue from up and change to left. We track these rules in turns.
 */

class Solution {
public:
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_map<int, int> turns[7] {
                                     {{-1, -1}},
                                     {{0, 0}, {1, 1}},
                                     {{2, 2}, {3, 3}},
                                     {{0, 2}, {3, 1}},
                                     {{3, 0}, {1, 2}},
                                     {{0, 3}, {2, 1}},
                                     {{2, 0}, {1, 3}}};
    bool trace(vector<vector<int>> &grid, int dir) {
        int i = 0, j = 0, m = grid.size(), n = grid[0].size();
        while(min(i, j) >= 0 && i < m && j < n) {
            if (turns[grid[i][j]].count(dir) == 0)
                return false;
            dir = turns[grid[i][j]][dir];
            if (i == m - 1 && j == n - 1)
                return true;
            i += dirs[dir].first, j += dirs[dir].second;
        }
        return false;        
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        for (auto d = 0; d < 4; ++d)
            if (trace(grid, d))
                return true;
        return false;
    }
};
