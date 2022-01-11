class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;
        int counts[26] = {0};
        for (int i = 0; i < s.size(); ++i) ++counts[s[i]-'a'];
        std::map<int,vector<char>> count2chars;
        for (int i = 0; i < 26; ++i) count2chars[counts[i]].push_back('a'+i);
        int max_count = count2chars.rbegin()->first;
        if (max_count == 1) return s;
        int chars_max = count2chars.rbegin()->second.size();
        int required_chars = (k-chars_max) * (max_count-1);
        if (required_chars > 0 && (required_chars > (s.size()-max_count*chars_max))) return "";
        vector<vector<char>> rearrange(max_count);
        for (const char c : count2chars.rbegin()->second) {
            for (int i = 0; i < max_count; ++i) {
                rearrange[i].push_back(c);
            }
        }
        auto iter = ++count2chars.rbegin();
        int row_index = 0;
        for (; iter != count2chars.rend(); ++iter) {
            int count = iter->first;
            for (const char c :  iter->second) {
                for (int i = 0; i < count; ++i) {
                    rearrange[row_index++].push_back(c);
                    row_index %= (max_count-1);
                }
            }
        }
        string ans;
        for (int i = 0; i < rearrange.size(); ++i) {
            for (int j = 0; j < rearrange[i].size(); ++j) {
                ans.append(1, rearrange[i][j]);
            }
        }
        return ans;
    }
};
