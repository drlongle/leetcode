/*
1217. Play with Chips
Easy

There are some chips, and the i-th chip is at position chips[i].

You can perform any of the two following types of moves any number of times (possibly zero) on any chip:
- Move the i-th chip by 2 units to the left or to the right with a cost of 0.
- Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
There can be two or more chips at the same position initially.

Return the minimum cost needed to move all the chips to the same position (any position).

Example 1:
Input: chips = [1,2,3]
Output: 1
Explanation: Second chip will be moved to positon 3 with cost 1. First chip will be moved to position 3 with cost 0. Total cost is 1.

Example 2:
Input: chips = [2,2,2,3,3]
Output: 2
Explanation: Both fourth and fifth chip will be moved to position two with cost 1. Total minimum cost will be 2.
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

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int res = numeric_limits<int>::max();
        map<int, int> lookup;
        for (int c: chips)
            ++lookup[c];

        for (auto& p1: lookup) {
            int cost = 0;
            for (auto& p2: lookup) {
                int diff = abs(p1.first - p2.first);
                if (diff % 2 == 1) {
                    cost += p2.second;
                }
            }
            res = min(res, cost);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> chips;

    // Output: 1
    chips = {1,2,3};

    chips = {2,2,2,3,3};
    
    cout << "Result: " << sol.minCostToMoveChips(chips) << endl;

    return 0;
}
