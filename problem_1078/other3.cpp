class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string term = first + " " + second + " ";
        int pos = text.find(term);
        vector<string> res;
        while (pos >= 0) {
            if (pos > 0 && text[pos - 1] != ' ') {
                pos = text.find(term, pos + 1);
                continue;
            }
            int i = pos + term.size();
            while(i < text.size() && text[i] != ' ') i++;
            res.push_back(text.substr(pos + term.size(), i - pos - term.size()));
            
            if (text.size() - pos - term.size() > 0) 
                pos = text.find(term, pos + 1);
        }
        return res;
    }
};
