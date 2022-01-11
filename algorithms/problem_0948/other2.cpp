class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int n=t.size();
        --n;
        sort(t.begin(),t.end());
        int a=0,s,m=0;
        for(int i=0;i<=n;i++)
        {
            if(p>=t[i])
            {
                a++;
                cout<<t[i];
                p=p-t[i];
                m=max(m,a);
            }
            else if(a>0)
            {
                --a;
                --i;
                p+=t[n];
                --n;
            }
            else
                break;
        }
        return m;
    }
};
