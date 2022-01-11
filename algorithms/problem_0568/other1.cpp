class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int k = days[0].size();
        int n = days.size();
        vector<int> dp(n, INT_MIN);
        vector<int> tmp(n, INT_MIN);
        dp[0] = 0;
        tmp[0] = 0;
        vector<vector<int>> es(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (flights[i][j] == 1)
                {
                    es[i].push_back(j);
                }
            }
        }

        for (int d = 0; d < k; d++)
        {
            for (int i = 0; i < n; i++)
            {
                if (dp[i] == INT_MIN)
                {
                    continue;
                }
                for (auto j : es[i])
                {
                    tmp[j] = max(dp[i] + days[j][d], tmp[j]);
                }
                tmp[i] =  max(dp[i] + days[i][d], tmp[i]);
            }
            dp = tmp;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
