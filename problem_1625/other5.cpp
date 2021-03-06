/*
If b is even, we only can modify digits in the even positions (odd will remain odd after the shift).
So, we need to inspect up to 10 variations of our string, each shifted up to n times, where n is
the size of the string. For each shift, we compare up to n elements.

If b is odd, we need to check up to 100 variations: 10 odd * 10 even, each shifted up to n times.
*/

class Solution {
public:
    bool less(string &s, int i, int j) {
        for (auto k = 0; k < s.size(); ++k) {
            if (s[(k + i) % s.size()] != s[(k + j) % s.size()])
                return s[(k + i) % s.size()] < s[(k + j) % s.size()];
        }
        return false;
    }
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        bool odd[10] = {};
        while (odd[s[0] - '0'] == false) {
            odd[s[0] - '0'] = true;
            bool even[10] = {};
            while (even[s[1] - '0'] == false) {
                even[s[1] - '0'] = true;
                int best_r = 0;
                vector<bool> rotate(s.size());
                for (int r = b; !rotate[r]; r = (r + b) % s.size()) {
                    rotate[r] = true;
                    if (less(s, r, best_r))
                        best_r = r;
                }
                res = min(res, s.substr(best_r) + s.substr(0, best_r));
                for (int k = 1; k < s.size(); k += 2)
                    s[k] = '0' + (s[k] - '0' + a) % 10;
            }
            if (b % 2) {
                for (int k = 0; k < s.size(); k += 2)
                    s[k] = '0' + (s[k] - '0' + a) % 10;
            }
        }
        return res;
    }
};