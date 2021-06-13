class Solution {
public:
    bool palindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])  return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        if(words.size()<=1) return ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            string rev = string(words[i].rbegin(),words[i].rend());
            m[rev] = i+1;
        }
        for(int i=0;i<words.size();i++){
            if(m[words[i]] && i+1!=m[words[i]])  ans.push_back({i,m[words[i]]-1});

            for(int j=words[i].size()-1;j>=0;j--){
                if(palindrome(words[i].substr(j))){
                    if(m[words[i].substr(0,j)]){
                        ans.push_back({i,m[words[i].substr(0,j)]-1});
                    }
                }
            }
            for(int j=0;j<words[i].size();j++){
                if(palindrome(words[i].substr(0,j+1))){
                    if(m[words[i].substr(j+1)]){
                        ans.push_back({m[words[i].substr(j+1)]-1,i});
                    }
                }
            }
        }
        return ans;
    }
};
