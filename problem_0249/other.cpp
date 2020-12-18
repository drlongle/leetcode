class Solution {
public:
    string encode(string s) {
        string key = "";
        for(int i = 1; i < s.size(); i++) {
            int diff = s[i] - s[i-1];
            key += (diff + 26)%26;
        }
        return key;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        for(string s : strings)
            map[encode(s)].push_back(s);
        vector<vector<string>> result;
        for (auto& it : map)
            result.push_back(it.second);
        return result;
    }
};
