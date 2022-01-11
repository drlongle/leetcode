// Concatenation and sliding window

class Solution {
public:
    int minFlips(string s) {
        int mn1=0,mn2=0,n=s.length(),ans=INT_MAX;
        if(n<2)return 0;
        string S=s+s;
        vector<int>t1(2*n);
        vector<int>t2(2*n);
        for(int i=0;i<(2*n);i++){
            mn1+=((S[i]-'0')^(i%2));
            mn2+=((S[i]-'0')^((i+1)%2));
            t1[i]=mn1;t2[i]=mn2;
        }
        ans=min(ans,min(t1[n-1],t2[n-1]));
        for(int i=n;i<(2*n-1);i++)
            ans=min(ans,min(t1[i]-t1[i-n],t2[i]-t2[i-n]));
        return ans;
    }
};
