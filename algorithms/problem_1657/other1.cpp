class Solution {
public:
    bool closeStrings(const string& word1, const string& word2) {
        unordered_map<char,int> m;
        unordered_map<char,int> v;

        int i,k=0;
        int n=word1.length();
        int p=word2.length();

        if(n!=p)
            return false;

        for(i=0;i<n;i++)
        {
            m[word1[i]]++;
            v[word2[i]]++;
        }
        for(auto it: m)
        {
            if(v[it.first]==0)
                return false;

            k=(k^it.second)^v[it.first];
        }

        if(k==0)
            return true;
        else
            return false;
    }
};
