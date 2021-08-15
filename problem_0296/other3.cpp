class Solution {

public:

    int get_diff(vector<int> vec, int idx) {
        int sum  = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum += abs(vec[i] - idx);
        }
        return sum;
    }

    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        int r = rows[rows.size() / 2];
        sort(cols.begin(), cols.end());
        int c = cols[cols.size() / 2];
        int diff = get_diff(rows, r) + get_diff(cols, c);
        return diff;
    }
};
