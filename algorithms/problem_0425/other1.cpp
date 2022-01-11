class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, vector<string>> prefixMap;
        for (string w:words) {
            for (int i = 0; i < w.length(); ++i) {
                prefixMap[w.substr(0, i)].push_back(w);
            }
        }

        vector<vector<string>> res;
        vector<string> cur;
        dfs(prefixMap, res, 0, words[0].length(), cur);
        return res;
    }

private:
    void dfs(unordered_map<string, vector<string>>& prefixMap, vector<vector<string>>& res, int i, int n, vector<string>& cur) {
        if (i == n) {
            res.push_back(cur);
            return;
        }
        string prefix = "";
        for (int t = 0; t < i; ++t) {
            prefix += cur[t][i];
        }
        for (string w : prefixMap[prefix]) {
            cur.push_back(w);
            dfs(prefixMap, res, i + 1, n, cur);
            cur.pop_back();
        }
    }
};
