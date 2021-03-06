class Solution {
#define mod (int)(1e9 + 7)
    int allDone;
    vector<vector<int>> caps;
    vector<vector<int>> dp;
public:
    int numberWays(vector<vector<int>> &hats) {
        int n = hats.size();
        dp.resize(45, vector<int>(1050, -1)), caps.resize(41);
        allDone = (1 << n) - 1;

        for (int i = 0; i < n; i++)
            for (int c : hats[i])
                caps[c].push_back(i);

        return helper() % mod;
    }
    
    int helper(int c = 1, int mask = 0) {
        if (mask == allDone) return 1;
        if (c == 41) return 0;
        if (dp[c][mask] != -1) return dp[c][mask];

        int ans = helper(c + 1, mask) % mod;
        for (int p : caps[c]) {
            if (!(mask & (1 << p)))
                ans += helper(c + 1, mask | (1 << p)) % mod;
            ans %= mod;
        }
        return dp[c][mask] = ans % mod;
    }
};
