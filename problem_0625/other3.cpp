class Solution {
public:
    int smallestFactorization(int a) {
        unsigned long long int ans=0,m=1;
        int i;
        if(a<10)
            return a;
        //factorisation
        for(i=9;i>=2;i--){
            while(a%i==0){
                a/=i;
                ans=m*i+ans;
                m*=10;
            }
        }
        //a!=1 checked to see if answer was even possible
        if(ans>INT_MAX || a!=1)
            return 0;
        return ans;
    }
};
