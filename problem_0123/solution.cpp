/*
123. Best Time to Buy and Sell Stock III
Total Accepted: 59329 Total Submissions: 222129 Difficulty: Hard

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
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
    int maxProfit(vector<int>& prices, int begin, int end)
    {
        int lowest = prices[begin];
        int max_profit = 0;
        for (int i = begin+1; i <= end; ++i)
        {
            if (prices[i] < lowest)
                lowest = prices[i];
            int temp = prices[i] - lowest;
            if (temp > max_profit)
                max_profit = temp;
        }
        return max_profit;
    }

    int maxProfit(vector<int>& prices)
    {
        int nsize = prices.size();
        if (!nsize) return 0;
        int profit = maxProfit(prices, 0, nsize-1);
        for (int i = 1; i < nsize; ++i)
        {
            if (prices[i] <= prices[i-1]) continue;
            int p1 = maxProfit(prices, 0, i);
            int p2 = maxProfit(prices, i+1, nsize-1);
            if (profit < p1+p2)
                profit = p1+p2;
        }

        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices;
    prices = {2,1,2,0,1};
    cout << "Result: " << sol.maxProfit(prices) << endl;

    return 0;
}

