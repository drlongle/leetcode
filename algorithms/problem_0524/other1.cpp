class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(const auto& str: d){
            int i = 0;
            for(auto c: s) if(str[i] == c) i++;
            if(i == str.size() && str.size() >= res.size())
                if(str.size() > res.size() || str < res)
                    res = str;
        }
        return res;
    }
};
