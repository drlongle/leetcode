class Solution {
public:
    void reverseWords(vector<char>& s) {
        // reverse entire string
        std::reverse(s.begin(), s.end());
        int i=0, beg = 0;
        // reverse each word
        while (i<s.size()) {
            if (s[i] == ' ') {
                std::reverse(s.begin()+beg, s.begin()+i);
                beg = i+1;
            }
            ++i;
        }
        // reverse last word
        std::reverse(s.begin()+beg, s.end());
    }
};
