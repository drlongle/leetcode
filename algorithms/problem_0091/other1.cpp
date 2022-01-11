class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 1);
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '0') {
                if (i == 0) return 0;
                if (i > 0 and stoi(s.substr(i-1, 2)) <= 26 and stoi(s.substr(i-1, 2)) >= 10)  dp[i + 1] = dp[i - 1];
                else dp[i + 1] = 0;
            }
            else {
                dp[i + 1] = dp[i];
                if (i >= 1 and stoi(s.substr(i-1, 2)) <= 26 and stoi(s.substr(i-1, 2)) >= 10)  dp[i + 1] += dp[i - 1];
            }
        }
        return dp.back();
    }
};

