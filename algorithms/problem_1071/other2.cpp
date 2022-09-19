class Solution {
  private:
    string stringGCDEuclid(const string &s1, const string &s2) {
        // s1.length > s2.length is assumed
        if (s2 == "")
            return s1;
        const int n1 = s1.size(), n2 = s2.size();
        const int rat = n1 / n2;
        for (int i = 0, j = 0; i < rat * n2; i++, j = (j + 1) % n2) {
            if (s1[i] != s2[j])
                return string();
        }
        return stringGCDEuclid(s2, string(s1.begin() + rat * n2, s1.end()));
    }

  public:
    string gcdOfStrings(string s1, string s2) {
        if (s1.size() > s2.size())
            return stringGCDEuclid(s1, s2);
        else
            return stringGCDEuclid(s2, s1);
    }
};
