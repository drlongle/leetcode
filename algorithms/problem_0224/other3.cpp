class Solution {
public:
    int calculate(string s) {
        int i,j,v,c,sign,ans;

        sign=1;  ans=0;  v=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i]==' ')
                continue;

            if(s[i]>='0' && s[i]<='9')
                v=v*10+(s[i]-'0');
            else
            {
                ans+=sign*v;
                v=0;
            }

            if(s[i]=='+')
                sign=1;
            else if(s[i]=='-')
                sign=-1;

            if(s[i]=='(')
            {
                c=1;
                for(j=i+1;j<s.length();j++)
                {
                    if(s[j]=='(')
                        c++;
                    else if(s[j]==')')
                        c--;
                    if(c==0)
                        break;
                }
                v=calculate(s.substr(i+1,j-i-1));
                ans+=sign*v;
                v=0;
                i=j;
            }
        }
        ans+=sign*v;

        return ans;
    }
};
