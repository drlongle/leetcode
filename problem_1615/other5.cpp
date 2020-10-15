class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n), idx(n);
        iota(begin(idx), end(idx), 0);
        size_t res = 0;
        unordered_set<int> adj;
        for (auto r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
            adj.insert((min(r[0], r[1]) << 16) + max(r[0], r[1]));
        }
        sort(begin(idx), end(idx), [&](int i, int j) {return cnt[i] > cnt[j]; });
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                if (res > cnt[idx[i]] + cnt[idx[j]])
                    break;
                res = max(res, cnt[idx[i]] + cnt[idx[j]] -
                               adj.count((min(idx[i], idx[j]) << 16) + max(idx[i], idx[j])));
            }
        }
        return res;
    }
};