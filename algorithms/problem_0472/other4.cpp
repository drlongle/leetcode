class Solution {
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());

        for (auto &word : words) {
            if (word == "") {
                continue;
            }
            dict.erase(word);
            vector<bool> dp(word.size(), true);
            if (dfs(dict, word, 0, dp)) {
                res.push_back(word);
            }
            dict.insert(word);
        }
        return res;
    }

  private:
    bool dfs(unordered_set<string> &dict, string &word, int index,
             vector<bool> &dp) {
        if (index == word.size()) {
            return true;
        }
        if (!dp[index]) {
            return false;
        }
        for (int len = 1; len + index <= word.size(); len++) {
            string str = word.substr(index, len);
            if (dict.count(str) != 0) {
                if (dfs(dict, word, index + len, dp)) {
                    return true;
                }
            }
        }
        dp[index] = false;
        return false;
    }
};
