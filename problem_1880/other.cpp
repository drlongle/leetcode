/*
  Replace letters with corresponding numbers, and then use a standard string-to-number conversion.
  'a' - '0' == 49.
 */

class Solution {
public:
    bool isSumEqual(string first, string second, string target) {
        auto op = [](string &s) { for(auto &ch : s) ch -= 49; return s; };
        return stoi(op(first)) + stoi(op(second)) == stoi(op(target));
    }
};
