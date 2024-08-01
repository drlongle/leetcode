/*
714. Best Time to Buy and Sell Stock with Transaction Fee
Medium

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i;
and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Note:
0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int lo = prices[0], hi = prices[0], sz = prices.size();

        for (int i = 0; i < sz; ++i) {
            int curr = prices[i];
            hi = max(hi, curr);
            if ((hi - fee > curr || curr < lo) && hi - lo >= fee) {
                profit += hi - lo - fee;
                hi = lo = curr;
            } else if (curr < lo)
                hi = lo = curr;
        }

        if (hi - lo > fee)
            profit += hi - lo - fee;

        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    int fee;

    // Output: 8
    prices = {1, 3, 2, 8, 4, 9}, fee = 2;
    cout << sol.maxProfit(prices, fee) << endl;

    // Output: 0
    prices = {9,8,7,1,2}, fee = 3;
    cout << sol.maxProfit(prices, fee) << endl;

    // Output: 4
    prices = {4,5,2,4,3,3,1,2,5,4}, fee = 1;
    cout << sol.maxProfit(prices, fee) << endl;

    // Output: 4
    prices = {2,1,4,4,2,3,2,5,1,2}, fee = 1;
    cout << sol.maxProfit(prices, fee) << endl;

    return 0;
}
