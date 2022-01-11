class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string res;
        for (int i = 0; i < n; ++i) {
            if (res.empty())
                res = s[0];
            dp[i][i] = true;
            if (i+1 < n && s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if (res.size() < 2) {
                    res = s.substr(i, 2);
                }
            }
        }

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = i+len-1;
                if (j < n && s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (res.size() < len)
                        res = s.substr(i, len);
                }

            }
        }

        return res;
    }
};