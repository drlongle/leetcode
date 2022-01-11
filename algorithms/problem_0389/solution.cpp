class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> cnt;
        for (auto ch: s)
            ++cnt[ch];
        for (auto ch: t) {
            auto it = cnt.find(ch);
            if (it == cnt.end()) {
                return ch;                
            }

            if (--(it->second) == 0)
                cnt.erase(it);
        }
        return 'a';
    }
};
