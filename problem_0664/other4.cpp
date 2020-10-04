class Solution {
public:
    // It is similar problem to clear the string. https://codeforces.com/contest/1132/problem/F

    int dp[1005][1005];

    int kil(int l, int r, string &s)
    {
        if(l > r)
            return 0;
        if(l == r)
            return 1;

        if(dp[l][r] != -1)
            return dp[l][r];

        //delete single character.
        dp[l][r] = 1 + kil(l+1, r, s);

        for(int i=l+1;i<=r;i++)
        {
            // matching some character with first character in range.
            // since deletion cost for both will be same unit only.
            // threfore we select the ith element and from l+1 create the new range
            // since deleting of ith character will be with lth character and not add any cost.
            if(s[l] == s[i])
                dp[l][r] = min(dp[l][r], kil(l+1, i, s) + kil(i+1, r, s));
        }
        return dp[l][r];
    }

    int strangePrinter(string s) {
        memset(dp, -1, sizeof dp);
        return kil(0, s.length()-1, s);
    }
};
