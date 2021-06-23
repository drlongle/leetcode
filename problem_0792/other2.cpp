class Solution {
public:
    bool isSubsequence(string& s, string& t)
    {
        int i=0, j=0;
        while(i<t.size() && j<s.size())
        {
            if(t[i]==s[j]) {  j++;  }
            i++;
        }
        if(j==s.size()) return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int c=0;
        for(int i=0;i<words.size();i++)
        {
            if(isSubsequence(words[i], s))
            {
                c++;
                while(i<words.size()-1 && words[i]==words[i+1])
                {  c++;  i++;  }
            }
            else
            {
                while(i<words.size()-1 && words[i]==words[i+1]) i++;
            }
        }
        return c;
    }
};
