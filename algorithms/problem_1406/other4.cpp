class Solution {
public:
    int dp[50001] = {};
    int dfs(vector<int>& sv, int p) {
        if (p >= sv.size())
            return 0;
        if (dp[p] != 0)
            return dp[p];
        auto sum = 0, res = INT_MIN;
        for (auto i = 0; i < 3 && p + i < sv.size(); ++i) {
            sum += sv[p + i];
            res = max(res, sum - dfs(sv, p + i + 1));
        }
        return dp[p] = res;
    }
    string stoneGameIII(vector<int>& sv) {
        auto res = dfs(sv, 0);
        return res == 0 ? "Tie" : res < 0 ? "Bob" : "Alice";
    }
};
