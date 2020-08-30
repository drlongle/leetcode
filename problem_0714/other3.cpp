class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buyHold(n, 0);//dp that stores the minimum cost of holding or buying the stock on day i
        vector<int> sellWait(n, 0);//dp that stores the current maximum profit if you sell the stock or wait to buy on day i
        buyHold[0] = prices[0];
        sellWait[0] = 0;
        for(int i=1; i<n; i++){
            buyHold[i] = min(prices[i]-sellWait[i-1], buyHold[i-1]);
            sellWait[i] = max(prices[i]-buyHold[i-1] - fee, sellWait[i-1]);
        }
        return sellWait[n-1];

    }
};
