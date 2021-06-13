class Solution {
public:
    string minWindow(string s1, string s2) {
        unordered_map <char, int> cnt;
        for (char c: s2)
            ++cnt[c];
        int begin = 0, end = 0, sz = s1.size(), counter = cnt.size();
        pair<int, int> res{-1, -1};
        while (begin < sz) {
            char c = s1[begin++];
            auto it = cnt.find(c);
            if (it == cnt.end()) {
                continue;
            }

            if (--it->second == 0)
                --counter;
            if (!counter) {
                while (end < begin) {
                    c = s1[end++];
                    it = cnt.find(c);
                    if (it == cnt.end())
                        continue;
                    if (it->second++ == 0) {
                        ++counter;
                        if (res.first < 0 || res.second - res.first > begin - end)
                            res = make_pair(end-1, begin-1);
                        break;
                    }
                }
            }
        }
        return res.first < 0 ? "" : s1.substr(res.first, res.second - res.first +1);
    }
};