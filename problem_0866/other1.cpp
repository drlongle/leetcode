#define ll int
class Solution {
public:
    bool isPrime(ll n){
        if(n==1)return false;
        for(ll i=2;i*i<=n;i++)
            if(n%i==0)return false;
        return true;
    }
    int primePalindrome(int n) {
        if(n>=8 and n<=11){
            return 11;
        }
        for(ll i=1;i<=1000000;i++){
            string s=to_string(i);
            string r(s.rbegin(),s.rend());
            string y=s+r.substr(1);
            ll y1=stoi(y);
            if(y1>=n and isPrime(y1))
                return y1;
        }
        return -1;
    }
};
