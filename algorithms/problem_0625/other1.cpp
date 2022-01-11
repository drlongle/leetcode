class Solution {
public:
    long smallestFactorization(int a) {
        if (a<10)
            return a;

        long ans=0;
        for (int i=9;i>=2;i--) //begin with ones place (begin with ones place 9 to minimize ans)
        {
            if((a%i)==0) //i=5 (15/5=0)
            {
                long pre=smallestFactorization(a/i);  // pre=3 (smallestFactori(15/5))

                if (pre == 0)                         //for prime numbers>7, pre=0
                    return 0;
                else
                {
                    string s=to_string(pre)+to_string(i);  //s=35
                    ans =stol(s);                          //ans=35
                    if (ans<INT_MAX)                       //check for 32-bit constraint
                        return ans;
                }
            }
        }

        return 0;
    }
};
