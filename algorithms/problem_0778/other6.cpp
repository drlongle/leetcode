class Solution {
public:
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> values(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        values[0][0] = grid[0][0];
        q.push({0, 0});

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int curr_x = x + x_points[i], curr_y = y + y_points[i];

                if (!isValid(curr_x, curr_y))
                    continue;

                int next = max(values[x][y], grid[curr_x][curr_y]);

                if (next < values[curr_x][curr_y]) {
                    q.push({curr_x, curr_y});
                    values[curr_x][curr_y] = next;
                }
            }
        }
        return values[n-1][m-1];
    }

private:
    vector<int> x_points = {-1, 1, 0, 0}, y_points = {0, 0, 1, -1};
    int n, m;
};
