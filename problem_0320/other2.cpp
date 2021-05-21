class Solution {
public:

    vector<string> ans;
    void helper(string s, string res, int index) {
        if (index == s.size()) {
            ans.push_back(res);
            return;
        }

        res.push_back(s[index]);
        helper(s, res, index+1);
        res.pop_back();

        if (!isdigit(res.back())) {
            for (int l=1; index+l<=s.size(); l++) {
                helper(s, res + to_string(l), index+l);
            }
        }
    }

    vector<string> generateAbbreviations(string word) {
        helper(word, "", 0);
        return ans;
    }
};
