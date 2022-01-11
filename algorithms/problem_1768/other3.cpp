class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int a=word1.size();
        int b=word2.size();
        int i=0,j=0;
        while(i<a||j<b)
        {
            if(i<a)
                ans.push_back(word1[i]);

            if(j<b)
                ans.push_back(word2[j]);

            i++;
            j++;
        }
        return ans;
    }
};
