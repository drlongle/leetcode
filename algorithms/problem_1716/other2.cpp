class Solution {
public:
    int totalMoney(int n)
    {
        int weeks=n/7,days=n%7;
        return 7*4*weeks+7*((weeks*(weeks-1))/2)+weeks*days+days+(days*(days-1))/2;
    }
};
