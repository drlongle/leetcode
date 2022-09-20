class Solution {
  public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        string t;
        int i = 0, sz = pattern.size();
        map<char, string> t1;
        map<string, char> t2;
        while (getline(iss, t, ' ')) {
            if (i >= sz)
                return false;
            char ch = pattern[i];
            auto [it, inserted] = t1.emplace(ch, t);
            if (!inserted && it->second != t) {
                return false;
            }

            auto [it2, inserted2] = t2.emplace(t, ch);
            if (!inserted2 && it2->second != ch) {
                return false;
            }
            ++i;
        }

        return i == sz;
    }
};
