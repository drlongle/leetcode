class Solution {
public:
    int numWays(string s) {
        long n = s.length(),
        int ones=count(s.begin(), s.end(), '1');
        if(ones%3)
            return 0;
        if(ones==0)
            return (((n-2)*(n-1))/2)%1000000007;
        ones/=3;
        long cnt=0, z1=0, z2=0;
        for(auto c: s){
            if(c=='1') cnt++;
            if(cnt==ones) z1++;
            else if(cnt==2*ones) z2++;
        }
        return (z1*z2)%1000000007;
    }
};