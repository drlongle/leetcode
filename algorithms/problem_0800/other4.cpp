class Solution {
public:
    string similarRGB(string color) {
        string ret="#";
        int i, n=color.size();
        for(i=1; i<n; i+=2) {
            auto s=color.substr(i, 2);
            ret+=helper(s);
        }
        return ret;
    }
    string helper(string &s) {
        if (s[0]==s[1]) return s;
        int v=stoi(s, nullptr, 16);
        int k=v/17+(v%17>8?1:0);
        string dict="0123456789abcdef";
        return string(2, dict[k]);
    }
};
