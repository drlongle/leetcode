class Solution {
public:
    using Map = unordered_map<int, int>;
    bool canConvertString(string s, string t, int K, Map need = {}, int needs = 0) {
        if (s.size() != t.size())
            return false;
        // add needs
        for (auto i{ 0 }; i < s.size(); ++i) {
            auto diff = (t[i] - s[i] + 26) % 26;
            if (diff)
                ++need[diff], ++needs;
        }
        // del needs
        for (auto i{ 1 }; i <= K && needs; ++i) {
            auto diff = i % 26;
            if (need[diff])
                --need[diff], --needs;
        }
        return !needs; // no needs
    }
};
