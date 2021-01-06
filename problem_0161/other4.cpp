class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        int NS = s.size();
        int NT = t.size();

        if (NS > NT) return isOneEditDistance(t, s);

        if (NT - NS > 1) return false;

        for (int i = 0; i < NS; i++)
        {
            if (s[i] != t[i])
            {
                if (NS == NT)
                    return s.substr(i+1) == t.substr(i+1);
                else
                    return s.substr(i) == t.substr(i+1);
            }
        }

        return (NS + 1 == NT);
    }
};
