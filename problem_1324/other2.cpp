class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ws{ istream_iterator<string>{istringstream() =
                                                    istringstream(s)}, istream_iterator<string>{} };
        int max_sz = (*max_element(begin(ws), end(ws), [](string& s1, string& s2) {
                                                           return s1.size() < s2.size(); })).size();
        vector<string> res(max_sz);
        for (auto i = 0; i < max_sz; ++i) {
            for (auto j = 0; j < ws.size(); ++j) {
                if (i < ws[j].size())
                    res[i] += ws[j][i];
                else
                    res[i] += " ";
            }
            while (res[i].back() == ' ')
                res[i].pop_back();
        }
        return res;
    }
};
