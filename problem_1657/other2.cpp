struct Solution {
    bool closeStrings(string word1, string word2) {
        vector<int>f1(26,0),f2(26,0),v1(26,0),v2(26,0);
        for(char x:word1)f1[x-'a']++,v1[x-'a']=1;
        for(char x:word2)f2[x-'a']++,v2[x-'a']=1;
        sort(f1.begin(),f1.end()), sort(f2.begin(),f2.end());
        return f1==f2&&v1==v2;
    }
};
