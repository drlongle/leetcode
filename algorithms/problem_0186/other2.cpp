class Solution {

    const char SPACE = ' ' ;

public:
    void reverseWords(vector<char>& s) {
        reverse(begin(s), end(s));

        for (auto lo = s.begin(); lo != s.end();) {
            const auto hi = find( lo, end(s), SPACE);
            reverse(lo, hi );
            lo = hi;

            while (lo != end(s) && *lo == ' ' )
                ++lo;
        }
    }
};
