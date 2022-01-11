class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt[26] = {}, res = 0;
        for (auto ch :  allowed)
            ++cnt[ch - 'a'];
        for (auto &w : words)
            res += all_of(begin(w), end(w), [&](char ch){ return cnt[ch - 'a'];});
        return res;
    }
};
