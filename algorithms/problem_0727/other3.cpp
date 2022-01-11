/*
dp[i][j] = The right-most index 'idx' in the string s1[0..i] such that the substring s1[idx..i]
contains the string s2[0..j] as a subsequence. If there is no such index that can contain s2[0..j]
as subsequence, then dp[i][j] = -1.
*/

class Solution {
public:
    string minWindow(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();

        vector<vector<int>> dp = vector(m, vector(n, 0));

        for (int i = 0; i < m; i++)
        {
            if (s1[i] == s2[0]) dp[i][0] = i;
            else
            {
                if (i == 0) dp[i][0] = -1;
                else dp[i][0] = dp[i-1][0];
            }
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (i < j)
                {
                    dp[i][j] = -1;
                }
                else
                {
                    if (s1[i] == s2[j])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        int mn = INT_MAX;
        int start = -1;

        for (int i = 0; i < m; i++)
        {
            if (dp[i][n-1] != -1 and i - dp[i][n-1] + 1 < mn)
            {
                mn = i - dp[i][n-1] + 1;
                start = dp[i][n-1];
            }
        }

        return (start == -1) ? "" : s1.substr(start, mn);
    }
};
