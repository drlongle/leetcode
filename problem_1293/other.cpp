struct State {
    int row, col, life, dep;
    State(int row_, int col_, int life_, int dep_) : row(row_), col(col_), life(life_), dep(dep_) {}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        visited[0][0][k] = 1;
        queue<State> frontier;
        frontier.push({0, 0, k, 0});
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        };
        while (!frontier.empty()) {
            State curr = frontier.front();
            frontier.pop();
            if (curr.row == m - 1 && curr.col == n - 1) {
                return curr.dep;
            }
            // Add all unvisited neighbors.
            for (pair<int, int> dir : dirs) {
                State nbr(curr.row + dir.first, curr.col + dir.second, curr.life, curr.dep + 1);
                if (nbr.row < 0 || nbr.row >= m || nbr.col < 0 || nbr.col >= n) continue;
                if (grid[nbr.row][nbr.col]) {
                    --nbr.life;
                }
                if (nbr.life < 0) continue;
                if (visited[nbr.row][nbr.col][nbr.life]) continue;
                visited[nbr.row][nbr.col][nbr.life] = 1;
                frontier.push(nbr);
            }
        }
        return -1;
    }
};
