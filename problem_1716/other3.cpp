class Solution {
public:
    int totalMoney(int n)
    {
        int noOfWeeks = n/7;
        int remDays = n%7;
        int i,totalSum = 0;
        for(i=1;i<noOfWeeks+1;i++)
            totalSum += 7*(i+3);
        totalSum += remDays * (2*i+remDays-1) /2;
        return totalSum;

    }
};
