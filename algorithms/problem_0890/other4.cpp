class Solution {
public:
    bool match(string a,string b)
    {
        vector<int>v(26,-1),used(26,0);
        for(int i=0;i<a.size();i++)
        {
            int x=a[i]-'a';
            int y=b[i]-'a';
            if(v[x]==-1 && used[y]==0)
            {
                v[x]=y;
                used[y]=1;
            }
            else if(v[x]!=y)
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>res;
        for(auto w:words)
        {
            if(match(w,pattern))
                res.push_back(w);
        }
        return res;
    }
};
