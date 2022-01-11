class Solution {
public:
    bool make(string s , string pattern)
    {
        vector<int> v1(26,-1); // map string to pattern
        vector<int> v2(26,-1); // map pattern to string
        for(int i=0; i<s.length(); i++)
        {
            if(v1[s[i]-'a'] == -1 && v2[pattern[i]-'a'] == -1)
            {
                v1[s[i]-'a'] = pattern[i]-'a';
                v2[pattern[i]-'a'] = s[i]-'a';
            }
            else if(v1[s[i]-'a'] != pattern[i]-'a' || v2[pattern[i]-'a'] != s[i]-'a')
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ans;
        for(string s : words)
        {
            if(make(s , pattern))
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
