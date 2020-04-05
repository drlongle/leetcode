class Solution {
public:
    int numSteps(string &s) {
        int res = 0, rem = 0;
        for (auto i = s.size() - 1; i > 0; --i) {
            if (s[i] - '0' + rem == 1) {
                rem = 1;
                res += 2;
            } 
            else
                res += 1;   
        }
        return res + rem;
    }
};
