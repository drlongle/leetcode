class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }

        string ans, key;
        bool openBracket = false;

        for (auto c : s) {
            if (isalpha(c)) {
                if (openBracket) {
                    key += c;
                } else {
                    ans += c;
                }
            } else if (c == '(') {
                openBracket = true;
            } else {
                openBracket = false;
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }

                key = "";
            }
        }

        return ans;
    }
};
