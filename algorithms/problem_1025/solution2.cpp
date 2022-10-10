class Solution {
  public:
    map<int, bool> dp;
    bool divisorGame(int n) {
        if (n == 1)
            return false;
        auto it = dp.find(n);
        if (it != dp.end())
            return it->second;
        set<int> cands{1};
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                if (!divisorGame(n - i))
                    return dp[n] = true;
            }
        }

        return dp[n] = false;
    }
};
