class Solution {
public:
    string minWindow(string s1, string s2) {
        int i,j,len1=s1.length(),len2=s2.length(),id1=0,id2=0,len=INT_MAX,start=-1;
        if(!len1 || !len2)return "";
        while(id1<len1){
            if(s1[id1]==s2[id2])id2++;
            if(id2==len2){
                int last=id1+1;
                while(--id2>=0){
                    while(s1[id1--]!=s2[id2]);
                }
                id1++;
                id2++;
                if(last-id1 < len){
                    len=last-id1;
                    start=id1;
                }
            }
            id1++;
        }
        return start==-1? "":s1.substr(start,len);
    }
};
