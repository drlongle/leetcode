// Concatenation and sliding window

class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        s+=s;
        int k1=0,k2=0;
        int x=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=x+'0')
                k1++;
            if(s[i]==x+'0')
                k2++;
            x^=1;
        }
        int mn=INT_MAX;
        mn=min(mn,min(k1,k2));
        int y=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==y+'0')
                k2--;
            else
                k1--;
            if(s[i+n]==x+'0')
                k2++;
            else
                k1++;
            x^=1;
            y^=1;
            mn=min(mn,min(k1,k2));
        }
        return mn;

    }
};
