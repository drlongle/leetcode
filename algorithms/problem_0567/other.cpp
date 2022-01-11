class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len=s1.size();
        vector<int> dic1(26);
        vector<int> dic2(26);
        for(auto x:s1){
            dic1[x-'a']+=1;
        }
        int start=0; 
        for(int i=0;i<s2.size();i++){

            if(i>=len){
                dic2[s2[start]-'a']-=1;
                start++;
            }
            dic2[s2[i]-'a']+=1;
            
            if(dic1==dic2) return true;
        }
        return false;
    }
};
