class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int i=0;
        int rc = 1, ans, cc = 0; //rc -- current running counter; cc -- current customer count
        int tempProfit, profit = 0;
        int tot = 0; //waiting customers
        while(i<customers.size() || tot > 0) {
            if(i<customers.size()) tot += customers[i];
            if(tot >= 4) {
                cc += 4;
                tot -= 4;
            } else {
                cc += tot;
                tot = 0;
            }
            tempProfit = cc*boardingCost - (rc*runningCost);
            if(tempProfit > profit) {
                profit = tempProfit;
                ans = rc;
            }
            rc++;
            i++;
        }
        return profit == 0 ? -1 : ans;
    }
};
