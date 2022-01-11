// DP

class Solution {
public:
    string longestPrefix(string &s) {
        // Note:
        // i points to the prefix, j points to the suffix
        // dp: length of the happy string after considering i characters
        vector<int> dp(s.size());
        for (int i = 1, j = 0; i < s.size(); ++i) {
            if (s[i] == s[j])
                dp[i] = ++j;
            else if (j > 0) {
                j = dp[j - 1];
                --i;
            }
        }
        return s.substr(0, dp.back());
    }
};
