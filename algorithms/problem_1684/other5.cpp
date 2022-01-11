class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt[26] = {};
        int ans=0;
        for (auto ch: allowed)
            cnt[ch - 'a']++;
        for(auto word:words){
            bool validword=true;
            for(int i=0;i<word.size();i++){
                if(cnt[word[i]-'a']==0){
                    validword=false;
                    break;
                }
            }
            if(validword){
                ans++;
            }
        }

        return ans;
    }
};
