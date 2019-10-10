class Solution {
public:
    bool isValidPalindrome(string s, int k) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return dfs(s, 0, s.size() - 1, dp) <= k;
    }

private:
    int dfs(const string& s, int l, int r, vector<vector<int>>& dp){

        if(l == r) return 0;
        if(l + 1 == r) return s[l] == s[r] ? 0 : 1;

        if(dp[l][r] != -1) return dp[l][r];

        int res = 1 + min(dfs(s, l + 1, r, dp), dfs(s, l, r - 1, dp));
        if(s[l] == s[r]) res = min(res, dfs(s, l + 1, r - 1, dp));
//        cout << l << "  - " << r << " : " << res << endl;
        return dp[l][r] = res;
    }
};
