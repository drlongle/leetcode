/*
464. Can I Win
Medium

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example
Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& key) const {
            return key.first ^ key.second;
        }
    };
}

class Solution {
public:

    bool check(const int mask, const int target) {
        auto key = make_pair(mask, target);
        auto it = dp.find(key);
        if (it != dp.end())
            return it->second;

        bool res = false;
        bool last_digit = ((mask & (mask-1)) == 0);
        for (int i = max_num; i >= 1 && !res; --i) {
            int shifted = 1 << i;
            if (mask & shifted) {
                if (i >= target) {
                    return dp[key] = true;
                } else if (last_digit) {
                    return dp[key] = false;
                }
                if (!check(mask & ~shifted, target -i))
                    res = true;
            }
        }

        return dp[key] = res;
    }

    unordered_map<pair<int, int>, bool> dp;
    int max_num;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int mask = 0;
        max_num = maxChoosableInteger;
        dp.clear();
        if (desiredTotal == 0) {
            return true;
        } else if ((maxChoosableInteger * (maxChoosableInteger+1))/2 < desiredTotal) {
            return false;
        }
        
        for (int i = 1; i <= maxChoosableInteger; ++i)
            mask |= (1 << i);
        
        return check(mask, desiredTotal);
    }
};

int main() {
    Solution sol;
    int maxChoosableInteger, desiredTotal;

    // Output: false
    maxChoosableInteger = 18;
    desiredTotal = 188;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    exit(0);
    
    // Output: false
    maxChoosableInteger = 5;
    desiredTotal = 50;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    
    // Output: 0
    maxChoosableInteger = 10;
    desiredTotal = 11;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;

    // Output: true
    maxChoosableInteger = 4;
    desiredTotal = 6;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;

    maxChoosableInteger = 18;
    desiredTotal = 79;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    
    // Output: 0
    maxChoosableInteger = 20;
    desiredTotal = 300;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;

    // Output: 0
    maxChoosableInteger =  10;
    desiredTotal = 40;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    
    // Output: 1
    maxChoosableInteger =  9;
    desiredTotal = 30;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    
    // Output: 1
    maxChoosableInteger = 8;
    desiredTotal = 21;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    
    maxChoosableInteger = 1;
    desiredTotal = 8;
    cout << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
    
    return 0;
}
