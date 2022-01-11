class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while (true) {
            iss >> word;
            if (iss)
                words.emplace_back(word);
            else
                break;
        }
        
        reverse(begin(words), end(words));
        ostringstream oss;
        for (int i = 0, sz = words.size(); i < sz; ++i) {
            if (i)
                oss << ' ';
            oss << words[i];
        }

        return oss.str();
    }
};
