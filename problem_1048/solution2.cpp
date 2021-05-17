class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> cnt;
        int res = 0;
        sort(begin(words), end(words), [] (auto& s1, auto& s2) {return s1.size() < s2.size();});
        for (auto& word: words) {
            int& r = cnt[word];
            r = max(r, 1);
            for (int i = 0, sz = word.size(); i < sz; ++i) {
                string w(word);
                w.erase(i, 1);
                auto it = cnt.find(w);
                if (it != cnt.end())
                    r = max(r, 1 + it->second);
            }
            res = max(res, r);
        }
        return res;
    }
};