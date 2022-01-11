class Solution {
    int count=0;
    vector<int> rotate= {0,1,-1,-1,-1,-1,9,-1,8,6};
    vector<int> nums={0,1,6,8,9};
    int max;
    // check current val, and generate next one with +1 length.
    void gen (long val)
    {
        if (valid(val))  count++ ;

        for (auto digit: nums)
        {
            if (val*10+digit> max) break;
            gen (val*10+digit);
        }
    }

    bool valid (int n)
    {
        int res=0;
        int orig=n;
        while (n)
        {
            int d=n%10;
            if (rotate[d]==-1) return false;
            res= res*10+ rotate[d];
            n/=10;
        }
        return res!= orig;
    }

public:
    int confusingNumberII(int N) {
        max =N;

        // exclude leading 0 , so we start from 1
        for (int i=1; i<5; i++)
            gen (nums[i]);

        return count;
    }
};
