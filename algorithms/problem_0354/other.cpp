

// O(Nlog(N))
struct Solution {
    int maxEnvelopes(vector<pair<int, int>>& es) {
        sort(es.begin(), es.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);});
        vector<int> dp;
        for (auto e : es)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e.second);
            if (iter == dp.end())
                dp.push_back(e.second);
            else if (e.second < *iter)
                *iter = e.second;
        }
        return dp.size();
    }
};

//DP O(N*N)
struct Solution {
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                    dp[i]  = max(dp[i] , dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};

