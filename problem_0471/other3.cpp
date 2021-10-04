class Solution {

    string compare(const string& encoded, const string& orig) {
        if (encoded.size() < orig.size())
            return encoded;
        return orig;
    }

    string encodeStr(const string& s, unordered_map<string, string>& dp) {
        if(s.size()<5)
            return s;
        if(dp.find(s) != dp.end())
            return dp[s];
        string ans = s;
        for (int size = 1; size <= s.size() / 2; size++) {
            if (s.size() % size)
                continue;
            string temp = s.substr(0, size);
            while (temp.size() < s.size()) {
                temp += s.substr(0, size);
                if(s.find(temp)!=0)
                    break;
            }
            if (temp == s) {
                string encoded = to_string(s.size() / size);
                encoded.push_back('[');
                encoded += encode(s.substr(0, size),dp);
                encoded.push_back(']');
                ans = compare(encoded, ans);

            }
        }
        return ans;
    }

    string encode(const string &s, unordered_map<string, string>& dp) {
        if (s.size() < 5)
            return s;
        if (dp.find(s) != dp.end())
            return dp[s];
        string ans = compare(encodeStr(s, dp), s);
        for (int i = 1; i < s.size() ; i++) {
            ans = compare(ans,
                          encodeStr(s.substr(0, i), dp)
                          + encode(s.substr(i), dp));
        }
        return dp[s] = ans;
    }
public:
    string encode(string s) {
        unordered_map<string, string>dp;
        return encode(s, dp);
    }
};
