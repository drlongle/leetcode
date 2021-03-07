/*
1. Sort all the words in descending order of their lengths.
2. Initialise res with first word in the vector + "#"
3. Now we just need to find, if other words in the vector + # are substring of res or not.
4. if not, append that word to res.
*/

bool compare(string &a,string &b){
    return a.length()>b.length();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        string res="";
        res=res+words[0]+"#";

        for(int i=1;i<words.size();i++){
            int pos=res.find(words[i]+"#");
            if(pos!=-1)
                continue;
            else
                res+=words[i]+"#";
        }

        return res.length();
    }
};
