class Solution {
public:

    string alienOrder(const vector<string>& words) {
        vector<vector<int>> links(26);
        set<int> alphabet;
        for (int i=0; i<words.size(); ++i) {
            for (const char & ch : words[i])
                alphabet.insert(ch-'a');
            if (i) {
                int len = std::min(words[i-1].size(), words[i].size());
                for (int j=0; j<len; ++j) {
                    if (words[i-1][j] != words[i][j]) {
                        links[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                        break;
                    }
                    if (j == len-1 && words[i-1].size() > words[i].size())
                        return "";
                }
            }
        }

        string ret;
        while (alphabet.size()) {
            set<int> tails;
            for (const int & letter : alphabet)
                for (const int & tail : links[letter])
                    tails.insert(tail);

            if (tails.size() == alphabet.size())
                return "";

            for (const int & letter : alphabet)
                if (tails.find(letter) == tails.end())
                    ret.push_back(letter+'a');
            alphabet = tails;
        }
        return ret;
    }
};
