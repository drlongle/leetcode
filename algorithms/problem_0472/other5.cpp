class Solution {
  public:
    bool helper(const set<string> &unique_words, const string &word, int index,
                int count) {
        // If I reach the end of the string and included more than one word
        // return true;
        if (index == word.length() && count > 1) {
            return true;
        }
        int i = index;
        string tmp = "";
        bool res = false;
        while (i < word.length()) {
            tmp += word[i];
            if (unique_words.find(tmp) != unique_words.end()) {
                // Call helper for the rest of the string
                count += 1;
                res |= helper(unique_words, word, i + 1, count);
                count -= 1;
            }
            i++;
        }

        return res;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        set<string> unique_words;
        for (const string &word : words) {
            unique_words.insert(word);
        }

        vector<string> res;
        for (const string &word : words) {
            if (helper(unique_words, word, 0, 0)) {
                res.push_back(word);
            }
        }

        return res;
    }
};