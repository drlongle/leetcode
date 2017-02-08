/*
322. Coin Change
Total Accepted: 25115 Total Submissions: 99712 Difficulty: Medium

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin. 
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
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> count(amount+1, numeric_limits<int>::max());
        count[0] = 0;
        for (auto& c: coins)
        {
            for (int i = c; i <= amount; ++i)
            {
                if (count[i-c] != numeric_limits<int>::max() &&
                    count[i-c]+1 < count[i])
                    count[i] = count[i-c]+1;
            }
        }

        int res = count[amount];
        return res == numeric_limits<int>::max() ? -1 : res;
    }
};

int main()
{
    Solution sol;
    vector<int> coins;
    int amount;

    // Expected: 20 
    coins = {186,419,83,408};
    amount = 6249;
    cout << "Solution: " << sol.coinChange(coins, amount) << endl;

    return 0;
}

