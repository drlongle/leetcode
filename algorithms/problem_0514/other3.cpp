class Solution {
    vector<vector<int>> dp;
    int dfs(int &n, unordered_map<char, vector<int>> &cache, string &key,
            int iKey = 0, int prevIndex = 0) {
        if (iKey == key.size())
            return 0;
        if (dp[prevIndex][iKey] >= 0)
            return dp[prevIndex][iKey];
        int d = 1e5 + 1;
        for (auto i : cache[key[iKey]])
            d = min(d, min(abs(i - prevIndex), n - abs(i - prevIndex)) + 1 +
                           dfs(n, cache, key, iKey + 1, i));
        return dp[prevIndex][iKey] = d;
    }

  public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        unordered_map<char, vector<int>> cache;
        dp = vector<vector<int>>(ring.size(),
                                 vector<int>(key.size(), -1)); // ring, key
        for (int i = 0; i < n; i++)
            cache[ring[i]].push_back(i);
        return dfs(n, cache, key);
    }
};
