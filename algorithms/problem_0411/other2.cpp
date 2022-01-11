class Solution {
public:
    unordered_map<int, pair<string, int>> m[21] = {};
    pair<string, int> dfs(string &t, vector<vector<int>> &used, int mask, int i) {
        auto it = m[i].find(mask);
        if (it != end(m[i]))
            return it->second;
        if (i >= t.size()) {
            int size = t.size();
            if (mask != 0) {
                vector<int> conf;
                bool first = true;
                for (int n = 0; n < t.size(); ++n) {
                    if (mask & (1 << n)) {
                        if (first) {
                            conf = used[n];
                            first = false;
                        }
                        else {
                            auto it = set_intersection(begin(conf), end(conf), begin(used[n]), end(used[n]), begin(conf));
                            conf.resize(it-conf.begin());
                        }
                    }
                }
                size = conf.empty() ? 0 : t.size();
            }
            return m[i][mask] = { "", size };
        }
        auto [s, len] = dfs(t, used, mask ^ (1 << i), i + 1);
        string res = t.substr(i, 1) + s;
        int min_len = len + 1;
        for (int sz = 2; i + sz <= t.size(); ++sz) {
            auto [s, len] = dfs(t, used, mask, i + sz);
            if (min_len > len + 1) {
                min_len = len + 1;
                res = to_string(sz) + s;
            }
        }
        return m[i][mask] = { res, min_len };
    }
    string minAbbreviation(string t, vector<string>& dictionary) {
        vector<string> dict;
        for (auto w : dictionary)
            if (w.size() == t.size())
                dict.push_back(w);
        if (dict.empty())
            return to_string(t.size());
        vector<vector<int>> used(t.size());
        for (int i = 0; i < t.size(); ++i)
            for (auto j = 0; j < dict.size(); ++j)
                if (dict[j][i] == t[i])
                    used[i].push_back(j);
        return dfs(t, used, 0, 0).first;
    }
};