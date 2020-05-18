class Solution {
public:
    string largestNumber(vector<int>& cost, int t) {
        vector<string> dp(t + 1, "0");
        dp[t] = "";
        for (int i = t - 1; i >= 0; --i) {
            for (int n = 1; n <= 9; ++n) {
                int val = i + cost[n - 1];
                if (val <= t && dp[val] != "0")
                    if (dp[val].size() + 1 >= dp[i].size())
                        dp[i] = to_string(n) + dp[val];
            }
        }
        return dp[0];
    }
};
