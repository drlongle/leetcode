/*
1561. Maximum Number of Coins You Can Get
Medium

There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

In each step, you will choose any 3 piles of coins (not necessarily consecutive).
Of your choice, Alice will pick the pile with the maximum number of coins.
You will pick the next pile with maximum number of coins.
Your friend Bob will pick the last pile.
Repeat until there are no more piles of coins.
Given an array of integers piles where piles[i] is the number of coins in the ith pile.

Return the maximum number of coins which you can have.

Example 1:
Input: piles = [2,4,1,2,7,8]
Output: 9
Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last
one. Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one.
The maximum number of coins which you can have are: 7 + 2 = 9.
On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.

Example 2:
Input: piles = [2,4,5]
Output: 4

Example 3:
Input: piles = [9,8,7,6,5,1,2,3,4]
Output: 18

Constraints:
3 <= piles.length <= 10^5
piles.length % 3 == 0
1 <= piles[i] <= 10^4
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
    int maxCoins(vector<int>& piles) {
        int res = 0;
        map<int, int> cnt;
        for (int p: piles)
            ++cnt[p];

        while (!cnt.empty()) {
            auto rit = cnt.rbegin();
            if (--(rit->second) == 0)
                cnt.erase(rit->first);
            rit = cnt.rbegin();
            res += rit->first;
            if (--(rit->second) == 0)
                cnt.erase(rit->first);
            auto it = cnt.begin();
            if (--(it->second) == 0)
                cnt.erase(it);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> piles;

    piles = {2,4,1,2,7,8};
    cout << sol.maxCoins(piles) << endl;

    piles = {9,8,7,6,5,1,2,3,4};
    cout << sol.maxCoins(piles) << endl;

    return 0;
}
