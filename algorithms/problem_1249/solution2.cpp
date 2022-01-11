class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string r;
        for (int i = s.size() - 1, cnt = 0; i >= 0; --i) {
            char c = s[i];
            if (c == ')') {
                r.push_back(c);
                ++cnt;
            } else if (c == '(') {
                if (cnt > 0) {
                    --cnt;
                    r.push_back(c);
                }
            } else
                r.push_back(c);
        }
        reverse(begin(r), end(r));
        string res;
        for (int cnt = 0; char c: r) {
            if (c == '(') {
                res.push_back(c);
                ++cnt;
            } else if (c == ')') {
                if (cnt > 0) {
                    --cnt;
                    res.push_back(c);
                }
            } else
                res.push_back(c);
        }
        return res;
    }
};