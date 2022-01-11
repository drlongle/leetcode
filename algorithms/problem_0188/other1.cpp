/*
k needs then to be "fixed": despite being told that it represents the number of "transactions"
(ie: buy or sell operations), it is actually more like the number of profit-bearinng trades
(ie: selling, after having bought for less); furthermore, it is pointless to consider a k which is wildly
bigger than the number of days we are going to trade - and this in turn needs to be reduced to an even
number to make sense (we would otherwise end up just buying for the last transaction, but it would be rather
pointless).

Hence the expression: min(k * 2, len - len % 2).

We do all this because we are going to create an array dp of values to help us, initialising all the odd
cells to 0 and all the even ones to INT_MAX.

Then it is time to loop through our list of prices for good, storing them as currPrice.

And for each one, we apply the generalised version of the logic I mentioned above:

the very first cell of dp is going to be set as the minimum between its current value and currPrice - min(dp[0], currPrice);
each following odd indexed cell is going to be the maximum between its current value and currPrice minus the prevous one - max(dp[i], currPrice - dp[i - 1]);
each following even indexed cell is going to be the minimum between its current value and currPrice minus the prevous one - min(dp[i], currPrice - dp[i - 1]);
After we are done, we can just return the value of the last cell :)
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        // edge cases away
        if (!k || len < 2) return 0;
        // fixing k to be a meaningful, even number
        k = min(k * 2, len - len % 2);
        // declaring and setting up dp
        int dp[k];
        for (int i = 0; i < k; i++) dp[i] = i % 2 ? 0 : INT_MAX;
        for (int currPrice: prices) {
            // setting up the first dp element
            dp[0] = min(dp[0], currPrice);
            // updating dp with all the subsequent trades
            for (int i = 1; i < k; i++) {
                // dp at even indices is the minimum price we can pay after buying a stock
                // dp at odd indices is the maxium price we can obtain after selling a stock
                dp[i] = i % 2 ? max(dp[i], currPrice - dp[i - 1]) : min(dp[i], currPrice - dp[i - 1]);
            }
        }
        return dp[k - 1];
    }
};
