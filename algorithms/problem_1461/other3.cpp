class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        map<string, int>mp;
        for(int i = 0; i<=s.size()-k; i++)
            mp[s.substr(i,k)]++;
         
        if(mp.size() == pow(2,k))return true;
        return false;
    }
};
