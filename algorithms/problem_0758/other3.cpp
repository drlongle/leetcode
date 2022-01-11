class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<bool> test(S.size(),false);

        for (auto& word : words) {
            int w_s = word.size();
            for (int i = 0; i < S.size()-w_s+1; ++i)
                if (S.substr(i,w_s) == word)
                    for (int j = i; j < i + w_s; ++j)
                        test[j] = true;
        }

        string res = "";
        for (int i = 0; i < test.size(); ++i) {
            if (test[i]) {
                if (i == 0 || !test[i-1])
                    res += "<b>";

                res.push_back(S[i]);

                if (i == test.size()-1 || !test[i+1])
                    res += "</b>";
            }
            else
                res.push_back(S[i]);
        }

        return res;
    }
};
