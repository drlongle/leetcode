class Solution {
  public:
    int rec(int l, int c, int n, vector<vector<int>> &dp) {
        if (l == n)
            return 0;
        if (dp[l][c] != -1)
            return dp[l][c];
        // copy or paste
        int copy = 1e9, paste = 1e9;
        if (c != l)
            copy = 1 + rec(l, l, n, dp);
        if (l + c <= n)
            paste = 1 + rec(l + c, c, n, dp);
        return dp[l][c] = min(copy, paste);
    }
    int minSteps(int n) {
        // at any point, you have two choices: copy current, or paste previous.
        // copy current updates the current copied length. (c = l) (if c!=l
        // already) paste on current adds the current copied length to the
        // current length. (l = l+c) (if c!=0) initially you will have to copy l
        // to paste it later. so c won't ever be 0 now.
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return 1 + rec(1, 1, n, dp);
    }
};
