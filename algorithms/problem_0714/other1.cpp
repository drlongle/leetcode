class Solution {
public:
// infinite transaction
// 3 choices -> buy, sell, do nothing
    int maxProfit(vector<int>& prices, int fee) {
        int Buy = -prices[0]; // (one bought) (keep minimum) (max of -ve) buy or do nothing - [take prev buy]
        int Sell = 0; // Sell at this or do nothing

        for(int i=1; i<prices.size(); i++){
            int nbuy=max(Buy, Sell-prices[i]);
            int nsell=max(Sell, Buy +prices[i]-fee);

            Buy = nbuy;
            Sell = nsell;
        }
        return Sell;
    }
};
