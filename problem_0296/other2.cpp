class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> cols;
        vector<int> rows;
        vector<pair<int, int>> pts;
        int res = 0;

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    cols.push_back(j);
                    rows.push_back(i);
                    pts.push_back({i, j});
                }
            }
        }

        sort(cols.begin(), cols.end());
        sort(rows.begin(), rows.end());

        int col = cols[cols.size()/2];
        int row = rows[rows.size()/2];

        for (auto it = pts.begin(); it != pts.end(); it++) {
            res += abs(it->first - row) + abs(it->second - col);
        }

        return res;
    }
};
