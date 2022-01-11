class Solution {
public:
    string boldWords(const vector<string>& words, const string& S) const {
        vector<bool> bold (S.size(), false);

        for (const auto& word : words) {
            size_t pos = S.find(word);
            while (string::npos != pos) {
                for (size_t idx = pos; idx < pos + word.size(); ++idx)
                    bold[idx] = true;
                ++pos;
                pos = S.find(word, pos);
            }
        }

        bool in_bold{false};
        string res = "";
        for (size_t idx = 0; idx < S.size(); ++idx) {
            if (bold[idx]) {
                if (!in_bold){
                    in_bold = true;
                    res.append("<b>");
                }
            } else {
                if (in_bold) {
                    in_bold = false;
                    res.append("</b>");

                }
            }
            res.push_back(S[idx]);
        }
        if (in_bold)
            res.append("</b>");

        return res;
    }
};
