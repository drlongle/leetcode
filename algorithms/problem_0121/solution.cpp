/*
121. Best Time to Buy and Sell Stock
Total Accepted: 107538 Total Submissions: 295527 Difficulty: Easy

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int lowest = prices[0];
        int max_profit = 0;
        int nsize = prices.size();
        for (int i = 1; i < nsize; ++i)
        {
            if (prices[i] < lowest)
                lowest = prices[i];
            int temp = prices[i] - lowest;
            if (temp > max_profit)
                max_profit = temp;
        }
        return max_profit;
    }
};

int main()
{
    Solution sol;

    return 0;
}

