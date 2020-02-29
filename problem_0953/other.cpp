class Solution {
public:
    
    void change(string& s, unordered_map<char,char>& m)
    {
        for(int i = 0; i < s.length(); ++i)
        {
            s[i] = (m.find(s[i]))->second;
        }
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> m;
        for(int i = 0; i < 26; ++i) m[order[i]] = 'a'+i;
        for(int i = 0; i < words.size(); ++i)
        {
            change(words[i],m);
        }
        for(int i = 1; i < words.size(); ++i)
        {
            if(words[i-1] > words[i]) return false;
        }
        return true;
    }
};
