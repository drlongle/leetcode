class Solution {
public:
    int xs(int cnt)
    {
        if (cnt == 0) return 0;
        else if (cnt == 1) return 1;
        else if (cnt <= 9) return 2;
        else if (cnt <= 99) return 3;
        return 4;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        for (int i = n-1; i >= 0; i--)
        {
            char c = s[i];
            for (int j = 0; j <= k; j++)
            {
                if (n - i <= j)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int cur = n - i;
                    if (j > 0)
                    {
                        cur = dp[i+1][j-1];
                    }
                    int remain = j;
                    int cnt = 1;
                    for (int t = i + 1; t < n; t++)
                    {
                        if (remain < 0) break;
                        cur = min(cur, dp[t][remain] + xs(cnt));
                        if (c == s[t])
                        {
                            cnt++;
                        }
                        else
                        {
                            remain--;
                        }
                    }
                    if (remain >= 0)
                    {
                        cur = min(cur, xs(cnt));
                    }
                    dp[i][j] = cur;

                }
            }
        }
        return dp[0][k];
    }
};
