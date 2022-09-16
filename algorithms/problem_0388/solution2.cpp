class Solution {
  public:
    int lengthLongestPath(string input) {
        string s;
        istringstream iss(input);
        int res = 0;
        map<int, int> lengths;
        while (getline(iss, s)) {
            int tabs = 0, len;
            for (int i = 0, sz = s.size(); i < sz; ++i, ++tabs) {
                if (s[i] != '\t') {
                    len = sz - i;
                    break;
                }
            }
            lengths[tabs] = len;
            for (int i = tabs - 1; i >= 0; --i)
                len += lengths[i] + 1;
            if (s.find('.') != string::npos)
                res = max(res, len);
        }

        return res;
    }
};
