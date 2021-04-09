class Solution {
public:
    int smallestFactorization(int a) {
        if(a==1)
            return 1;
        vector<int>  record;
        int limit=INT_MAX;
        int flag(0);
        while(a>=10)
        {
            flag=0;
            for(int i(9);i>=2;i--)
            {
                if(a%i==0)
                {
                    flag=1;
                    record.push_back(i);
                    a=a/i;
                    break;//think about 64, the correct answer should be 88 not 248
                    //so when we find a divisor, we need jump out from the current loop
                    //and attempt from 9 to 0
                }
            }
            if(!flag)
                return 0;//we set a flag, when flag==0. We know it's a prime number
        }
        if(a!=1)
            record.push_back(a);
        long long int result(0);
        for(int i(record.size()-1);i>=0;i--)
        {
            result*=10;
            result+=record[i];
        }//put the smaller digit at high position
        return (result>limit)?0:result;
    }
};
