class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp;
        dp.emplace_back(vector<int>(5, 1));
        for (int i = 2; i <= n; ++i) {
            dp.emplace_back(vector<int>(5, 0));
            for (int j = 0; j < 5; ++j) {
                for (int k = j; k < 5; ++k) {
                    dp[i-1][j] += dp[i-2][k];
                }
            }
        }
        return accumulate(begin(dp.back()), end(dp.back()), 0);
    }
};
