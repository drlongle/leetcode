// dp[i] maximal last index possible such that if we consider substring of s1 from that index to ith position,
// it will contain s2.
// dp[i] = i + 1 // Since empty string s2 will always be present in the current len = 1 substrings of s1;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int>dp(n + 1, 0);

        for(int i = 1; i <= n ; i++)
            dp[i] = i + 1;

        for(int j = 1; j <= m; j++)
        {
            int prev = (j == 1) ? 1 : 0;

            for(int i = 1; i <= n; i++)
            {
                int cur = dp[i];

                dp[i] = (s1[i - 1] == s2[j - 1]) ? prev : dp[i - 1];

                prev = cur;
            }
        }

        int len = n + 1;
        string ans = "";

        for(int i = 1; i <= n; i++)
        {
            if(dp[i] && (i - dp[i] + 1) < len)
            {
                len = i - dp[i] + 1;
                ans = s1.substr(dp[i] - 1, len);
            }
        }

        return ans;
    }
};
