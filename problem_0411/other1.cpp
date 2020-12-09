/*
Intuition
- Each character that appears in the abbreviation reduces the chance of a conflict.
- We should never replace a character with "1", as it neither reduces conflicts nor the abbreviation size.
- Words of a different (that the target) sizes can be ignored.

Solution: For each character in the target, we collect indexes of dictionary words that has that
character in the same position. We track which characters we selected to use in the abbreviation,
and we can use set intersection to check if the final abbreviation is conflicting or not.

We use DFS to enumerate all possible abbreviations. As we go through our target string, we have two choices:
- Pick the character to be used in the abbreviation. This reduces conflicts.
- Skip 2 or more characters (no need to skip one).
- If a final abbreviation is not conflicting, we consider it while picking the shortest one.

Approach:
We track conflicts as we go, and we do not use memoisation.
*/

class Solution {
public:
    pair<string, int> dfs(string &t, vector<vector<int>> &used, vector<int> &conf, int i, bool first) {
        if (i >= t.size())
            return { "", conf.empty() && !first ? 0 : t.size() };
        vector<int> n_conf;
        if (first)
            n_conf = used[i];
        else
            set_intersection(begin(conf), end(conf), begin(used[i]), end(used[i]), back_inserter(n_conf));
        auto [s, len] = dfs(t, used, n_conf, i + 1, false);
        string res = t.substr(i, 1) + s;
        int min_len = len + 1;
        for (int sz = 2; i + sz <= t.size(); ++sz) {
            auto [s, len] = dfs(t, used, conf, i + sz, first);
            if (min_len > len + 1) {
                min_len = len + 1;
                res = to_string(sz) + s;
            }
        }
        return { res, min_len };
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
        return dfs(t, used, vector<int>() = {}, 0, true).first;
    }
};