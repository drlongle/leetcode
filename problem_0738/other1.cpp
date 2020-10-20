class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n=s.length();
        if(n==1)
            return N;
        int i=n-1, j = 0,k;
        while(i)
        {
            if(s[i]<s[i-1])
            {
                j=i;k=i-1;
                s[k]=s[k]-1;
            }
            i--;
        }
        if (j) {
            for(i=j;i<n;i++)
                s[i]='9';
        }
        return stoi(s);
    }
};