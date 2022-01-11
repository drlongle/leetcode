class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int weeks = days[0].size();
        vector<vector<int>> dp(weeks+1, vector<int>(n, INT_MIN));
        dp[0][0] = 0;

        for (int k = 0; k < weeks; ++k){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (i == j or flights[i][j])
                        dp[k+1][j] = max(dp[k+1][j], dp[k][i] + days[j][k]);
                }
            }
        }
        return *max_element(dp[weeks].begin(), dp[weeks].end());
    }
};
