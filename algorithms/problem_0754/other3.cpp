class Solution {
public:
    int reachNumber(int t) {
        t=abs(t);
        int sum=0;
        int a=0;
        while(1)
        {
            sum+=a;
            if(sum%2 == t%2 && sum >= t)
            {
                return a;
            }
            a++;
        }
        return 0;
    }
};
