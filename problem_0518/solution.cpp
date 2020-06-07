/*
518. Coin Change 2
Medium

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Example 1:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10] 
Output: 1

Note:

You can assume that
0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
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
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for (int coin: coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coin >= 0)
                    dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};

 main() {
    Solution sol;
    vector<int> coins;
    int amount;

    // Output: 4
    amount = 5, coins = {1, 2, 5};
    cout << sol.change(amount, coins) << endl;
    
    // Output: 0
    amount = 3, coins = {2};
    cout << sol.change(amount, coins) << endl;
    
    // Output: 1
    amount = 10, coins = {10};
    cout << sol.change(amount, coins) << endl;

    return 0;
}
