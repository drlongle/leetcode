class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //This solution is based on the bottom up approach of dyanamic programming
        //The core idea of the problem
        //You have three options at every index and that is to either buy, sell or do nothing
        //dpBuy[i] <-- The max profit you can make till the ith day, assuming you buy on that day.
        //dpBuy[i] = max( do nothing, buy (you should have sold a stock last to buy on this day))
        //dpSell[i] <-- The max profit you can make till the ith day, assuming you sell on that day.
        //dpSell[i] = max(do nothing, sell (you should have purchased a stock last to sell on this day))

        int n = prices.size();
        vector<int> dpBuy(n, 0);
        vector<int> dpSell(n, 0);

        //base cases
        dpBuy[0] = -prices[0];
        dpSell[0] = 0;

        for(int i=1; i<n; i++){
            dpBuy[i] = max(dpBuy[i-1], dpSell[i-1]-prices[i]);
            dpSell[i] = max(dpSell[i-1], dpBuy[i-1]+prices[i]-fee);
        }

        return dpSell[n-1];
    }
};