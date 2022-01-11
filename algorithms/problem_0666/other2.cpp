class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> res(5, vector<int>(9, 0)), seen(5, vector<int>(9, 1));

        for (int& x : nums) {
            int val = x % 10;
            x /= 10;
            int col = x % 10;
            x /= 10;
            int row = x;
            res[row][col] = val + res[row-1][(col + 1) / 2];
            seen[row-1][(col + 1) / 2] = 0;
        }

        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 9; ++j) {
                ans += res[i][j] * seen[i][j];
            }
        }
        return ans;
    }
};
