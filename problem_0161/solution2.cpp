class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size())
            swap(s, t);
        int i = 0, j = 0, n1 = s.size(), n2 = t.size(), change = 0;
        if (n2 - n1 > 1)
            return false;
        while (i < n1 && j < n2) {
            if (s[i] == t[j]) {
                ++i, ++j;
                continue;
            }
            if (++change > 1)
                return false;
            ++j;
            if (n1 == n2) {
                ++i;
            }
        }

        return change == 1 || (i == n1 && j == n2-1);
    }
};
