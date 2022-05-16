class Solution {
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> ans;
        dict = move(unordered_set<string>(words.begin(), words.end()));
        dict.erase(""); // remove empty string

        for (auto &w : words) {
            if (canBeSepareted(w)) {
                ans.push_back(w);
            }
        }
        return ans;
    }

  private:
    bool canBeSepareted(string w) {
        if (cache.count(w) > 0) {
            return cache[w];
        }

        string prefixWord;
        string suffixWord;

        for (int i = 0; i < w.size(); ++i) {
            prefixWord += w[i];
            if (dict.count(prefixWord) == 0) {
                continue;
            }

            suffixWord = w.substr(i + 1);
            if (dict.count(suffixWord) > 0 || canBeSepareted(suffixWord)) {
                cache[w] = true;
                return true;
            }
        }

        cache[w] = false;
        return false;
    }

  private:
    unordered_set<string> dict;
    unordered_map<string, bool> cache;
};
