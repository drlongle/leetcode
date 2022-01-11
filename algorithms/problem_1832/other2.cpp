class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26)
            return false;
        map<char,int>mp;
        for(char i='a';i<='z';i++)
            mp[i]=0;
        for(int i=0;i<sentence.length();i++){
            mp[sentence[i]]++;
        }
        for(auto x:mp){
            if(x.second==0)
                return false;
        }
        return true;
    }
};
