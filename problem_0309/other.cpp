class Solution {
public:
    vector<vector<int>> dp;
    
    int get_profit(vector<int>& prices, int i, int j) {
        if (j <= i)
            return 0;
        int res = dp[i][j];
        if (res >= 0)
            return res;
        res = 0;
        for (int k = i, lowest = prices[i], highest = prices[i]; k <= j; ++k) {
            highest = max(highest, prices[k]);
            if (prices[k] < lowest) {
                res = max(res, highest - lowest + get_profit(prices, k+2, j));
                lowest = highest = prices[k];
            }

            res = max(res, highest - lowest + get_profit(prices, k+2, j));
        }
        return dp[i][j] = res;
    }
    
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        dp.resize(sz, vector<int>(sz, -1));
        
        return get_profit(prices, 0, sz-1);
    }
};
