/*
188. Best Time to Buy and Sell Stock IV
Total Accepted: 27738 Total Submissions: 122064 Difficulty: Hard

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int unlimited_maxProfit(vector<int>& prices)
    {
        if (prices.empty()) return 0;
        int lowest = prices[0];
        int highest = prices[0];
        int profit = 0;
        int nsize = prices.size();
        for (int i = 1; i < nsize; ++i)
        {
            int p = prices[i];
            if (p < lowest || p < highest)
            {
                profit += highest - lowest;
                lowest = highest = p;
            }
            else if (p > highest)
                highest = p;
        }
        profit += highest - lowest;
        return profit;
    }

    int maxProfit(int k, vector<int>& prices)
    {
        int nsize = prices.size();
        if (!nsize) return 0;
        if (k/2 >= nsize)
            return unlimited_maxProfit(prices);

        vector<int> prev(nsize, 0), curr(nsize, 0);
        int profit_at_buy, profit_at_sell;
        bool change = true;

        for (int c = 0; c < k && change; ++c)
        {
            change = false;
            prev  = curr;
            profit_at_buy = profit_at_sell = numeric_limits<int>::min();
            for (int i = 0; i < nsize; ++i)
            {
                int p = prices[i];
                profit_at_sell = max(profit_at_sell, p + profit_at_buy);
                profit_at_buy = max(profit_at_buy, prev[i-1] - p);
                if (profit_at_sell > curr[i])
                {
                    curr[i] = profit_at_sell;
                    change = true;
                }
             }
        }

        return curr[nsize-1];
    }
};

int main()
{
    Solution sol;
    vector<int> prices;
    int k = 2;

    // Expected: 3
    k = 2;
    prices = {1,4,2};
    cout << "Result: " << sol.maxProfit(k, prices) << endl;

    return 0;
}

