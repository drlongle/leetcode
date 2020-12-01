/*
1648. Sell Diminishing-Valued Colored Balls
Medium

You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color
you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the
first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then
valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color
that you initially own. You are also given an integer orders, which represents the total number of balls that
the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be
too large, return it modulo 10^9 + 7.

Example 1:
Input: inventory = [2,5], orders = 4
Output: 14
Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
The maximum total value is 2 + 5 + 4 + 3 = 14.

Example 2:
Input: inventory = [3,5], orders = 6
Output: 19
Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.

Example 3:
Input: inventory = [2,8,4,10,6], orders = 20
Output: 110

Example 4:
Input: inventory = [1000000000], orders = 1000000000
Output: 21
Explanation: Sell the 1st color 1000000000 times for a total value of 500000000500000000.
500000000500000000 modulo 10^9 + 7 = 21.

Constraints:
1 <= inventory.length <= 10^5
1 <= inventory[i] <= 10^9
1 <= orders <= min(sum(inventory[i]), 10^9)
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;
    int maxProfit(vector<int>& inventory, int orders) {
        map<int, int, greater<int>> cnt;
        for (int i: inventory)
            ++cnt[i];
        long long result = 0;

        while (orders > 0) {
            long long diff_level, next_level;
            long long curr_level = cnt.begin()->first;
            if (cnt.size() >= 2) {
                next_level = next(cnt.begin())->first;
            } else
                next_level = 0;
            int count = cnt.begin()->second;
            diff_level = min(static_cast<long long>(orders) / cnt.begin()->second, curr_level - next_level);
            next_level = curr_level - diff_level;

            if (diff_level > 0) {
                cnt[next_level] += count;
                cnt.erase(cnt.begin());
                result = (result + diff_level * (curr_level + next_level + 1) / 2 * count) % MOD;
                orders -= diff_level * count;
            } else {
                int rest_orders = orders - diff_level * count;
                int t = min(rest_orders, cnt.begin()->second);
                result = (result + curr_level * t) % MOD;
                orders -= t;
                cnt.begin()->second -= t;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> inventory;
    int orders;

    // Output: 14
    inventory = {2,5}, orders = 4;
    cout << sol.maxProfit(inventory, orders) << endl;

    // Output: 19
    inventory = {3,5}, orders = 6;
    cout << sol.maxProfit(inventory, orders) << endl;

    // Output: 110
    inventory = {2,8,4,10,6}, orders = 20;
    cout << sol.maxProfit(inventory, orders) << endl;

    // Output: 21
    inventory = {1000000000}, orders = 1000000000;
    cout << sol.maxProfit(inventory, orders) << endl;

    // Output: 72
    inventory = {8,9}, orders = 12;
    cout << sol.maxProfit(inventory, orders) << endl;

    // Output: 77
    inventory = {3,5,6,8,9}, orders = 12;
    cout << sol.maxProfit(inventory, orders) << endl;

    // 373219333
    inventory = {497978859,167261111,483575207,591815159}, orders = 836556809;
    cout << sol.maxProfit(inventory, orders) << endl;

    inventory = {680754224,895956841,524658639,3161416,992716630,7365440,582714485,422256708,332815744,269407767};
    orders = 707568720;
    cout << sol.maxProfit(inventory, orders) << endl;

    return 0;
}
