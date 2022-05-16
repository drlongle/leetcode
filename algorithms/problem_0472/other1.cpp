class Solution {
  public:
    bool check(string word, int index, int cnt, unordered_set<string> &st) {
        if (index == word.size()) {
            if (cnt >= 2) {
                return true;
            }
            return false;
        }
        for (int i = index; i < word.length(); ++i) {
            string temp = word.substr(index, i - index + 1);
            if (st.count(temp) && check(word, i + 1, cnt + 1, st)) {
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        unordered_set<string> st;
        for (auto str : words) {
            st.insert(str);
        }
        vector<string> arr;
        for (auto word : words) {
            if (check(word, 0, 0, st)) {
                arr.push_back(word);
            }
        }
        return arr;
    }
};
