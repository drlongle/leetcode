class Solution {
public:
    //This is used to determine if a has common subsequence in b
    bool hasCommon(string a,string b){
        int remine = a.size();
        int remine2 = b.size();
        for(;remine>0&&remine2>0;){
            int i = a.size()-remine;
            int j = b.size()-remine2;
            if(a.at(i) == b.at(j)){
                remine--;remine2--;
            }else{
                remine2--;
            }
        }
        return remine==0;
    }
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for(int i = 0;i<strs.size();++i){
            int currentLen = strs[i].length();
            bool all = true;
            for(int j = 0;j<strs.size();++j){
                if(i!=j&&hasCommon(strs[i], strs[j])){
                    all = false;
                    break;
                }
            }
            if(all){
                maxLen = maxLen<currentLen?currentLen:maxLen;
            }
        }
        return maxLen;
    }
};