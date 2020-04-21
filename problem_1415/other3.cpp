class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> v[11];
        v[1].push_back("a");
        v[1].push_back("b");
        v[1].push_back("c");
        for(int i=2;i<=n;i++)
        {
            for(string x:v[i-1])
            {
                int n=x.length();
                for(char j='a';j<='c';j++)
                {
                    if(x[n-1] != j)
                    {
                        string y=x+j;
                        v[i].push_back(y);
                    }
                }
            }
        }
        sort(v[n].begin(),v[n].end());
        if(v[n].size()<k)
            return "";
        return v[n][k-1];
    }
};
