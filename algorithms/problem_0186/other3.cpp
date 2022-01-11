class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size(), l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                r++;
            }
            else if (i > 0 && i != ' ') {
                reverse(s.begin() + l, s.begin() + r);
                r += 1;
                l = r;
            }
        }
        reverse(s.begin() + l, s.begin() + r);
    }
};
