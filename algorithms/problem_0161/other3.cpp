class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sl = s.size(), tl = t.size();

        if (abs(sl-tl) > 1)
            return false;

        for (int i = 0; i < min(sl,tl); ++i)
            if (s[i] != t[i]) {
                if (sl == tl)
                    return s.substr(i+1) == t.substr(i+1);
                if (sl > tl)
                    return s.substr(i+1) == t.substr(i);
                else
                    return s.substr(i) == t.substr(i+1);
            }

        return abs(sl-tl) == 1;
    }
};
