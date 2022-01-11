class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i1 = 1; i1 <=n1; ++i1) for (int i2 = 1; i2 <=n2; ++i2)  {
            int ans = 0;
            ans = max(dp[i1][i2-1], dp[i1-1][i2]);
            if (s1[i1-1]==s2[i2-1]) ans = max(ans, (int)s1[i1-1] + dp[i1-1][i2-1]);
            dp[i1][i2] = ans;
        }
        int ret = 0;
        for (auto c:s1) ret +=c;
        for (auto c:s2) ret +=c;
        ret -= 2*dp[n1][n2];
        return ret;
    }
};
