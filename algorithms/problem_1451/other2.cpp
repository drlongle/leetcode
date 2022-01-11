class Solution {
public:
    string arrangeWords(string text) {
        vector<string> v;
        string res = "";
        
        text[0] = tolower(text[0]);
        int first = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                v.push_back(text.substr(first, i - first));
                first = i + 1;
            } else if (i == text.size() - 1)
                v.push_back(text.substr(first, i - first + 1));
        }
        
        std::stable_sort(std::begin(v), std::end(v),
                 [](const auto &s1, const auto &s2) {
                     return s1.length() < s2.length();
                 });
        
        for (int i = 0; i < v.size(); i++) {
            res += v[i];
            if (i == 0)
                res[0] = toupper(res[0]);
            if (i != v.size() - 1)
                res += " ";
        }
        
        return res;
    }
};
