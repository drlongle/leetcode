/*
309. Best Time to Buy and Sell Stock with Cooldown

    Total Accepted: 25369

    Total Submissions: 65403
    Difficulty: Medium

Say you have an array for which the i-th element is the price of a given stock
on day i. Design an algorithm to find the maximum profit. You may complete as
many transactions as you like (ie, buy one and sell one share of the stock
multiple times) with the following restrictions:

    - You may not engage in multiple transactions at the same time (i.e., you
      must sell the stock before you buy again).
    - After you sell your stock, you cannot buy stock on next day (i.e.,
      cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    vector<int> profits;

    int maxProfit(vector<int>& prices) {
        int nsize = prices.size();
        int res = 0;
        if (nsize <= 1)
            return 0;
        profits.clear();
        profits.resize(nsize);
        for (int i = 1; i < nsize; ++i) {
            int temp = max(0, prices[i] - prices[0]);
            for (int j = 0; j < i; ++j) {
                temp = max(temp, (j > 0 ? profits[j-1] : 0) +
                                 (i > j+1 ? prices[i] - prices[j+1] : 0));
            }
            profits[i] = temp;
            if (res < temp) res = temp;
        }

        for (int i = 1; i < nsize; ++i) {
            int temp = max(profits[i], profits[i-1]);
            for (int j = 0; j < i; ++j) {
                temp = max(temp, (j > 0 ? profits[j-1] : 0) +
                                 (i > j+1 ? prices[i] - prices[j+1] : 0));
            }
            profits[i] = temp;
            if (res < temp) res = temp;
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> prices;

    // Expected: 3
    prices = {1, 2, 3, 0, 2};

    // Expected: 10
    prices = {2,1,4,5,2,9,7};

    // Expected: 7
    prices = {6,1,6,4,3,0,2};

    cout << "Result: " << sol.maxProfit(prices) << endl;

    return 0;
}

