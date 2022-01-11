class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '?')
            {
                char replace = 'a';
                while((i-1 >= 0 && s[i-1] == replace) || (i+1 <= s.size()-1 && s[i+1] == replace))
                {
                    replace++;
                }
                s[i] = replace;
            }

        }
        return s;
    }
};
