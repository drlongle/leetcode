class Solution {
  public:
    // same logic as word break
    bool dpsearch(string &word, unordered_set<string> &search) {

        vector<int> dp(word.length() + 1);
        dp[0] = true;

        int cnt = 0;
        for (int i = 1; i <= word.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] and
                    search.find(word.substr(j, i - j)) != search.end() &&
                    i - j != word.size()) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[word.length()];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {

        unordered_set<string> search;

        for (string c : words) {
            if (c.size() > 0)
                search.insert(c);
        }

        vector<string> ans;

        if (words.size() == 1) {
            return ans;
        }

        for (string word : words) {
            if (dpsearch(word, search) && word.size() > 0)
                ans.push_back(word);
        }

        return ans;
    }
};
