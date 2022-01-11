class Solution {
public:
    vector<char> mis;
    string decode (string s)
    {
        mis.assign(26,'0');
        string ans="";
        int curr = 1;
        for (auto x:s)
        {
            if (mis[x-'a']=='0')
                mis[x-'a']+=curr++;
            ans+=mis[x-'a'];
        }
        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string> ans;
        string p = decode(pattern);

        for (auto x:words)
            if (decode(x) == p)
                ans.push_back(x);
        return ans;
    }
};
