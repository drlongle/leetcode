/*
1155. Number of Dice Rolls With Target Sum
Medium

You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to
roll the dice so the sum of the face up numbers equals target.

Example 1:
Input: d = 1, f = 6, target = 3
Output: 1
Explanation:
You throw one die with 6 faces.  There is only one way to get a sum of 3.

Example 2:
Input: d = 2, f = 6, target = 7
Output: 6
Explanation:
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: d = 2, f = 5, target = 10
Output: 1
Explanation:
You throw two dice, each with 5 faces.  There is only one way to get a sum of
10: 5+5.

Example 4:
Input: d = 1, f = 2, target = 3
Output: 0
Explanation:
You throw one die with 2 faces.  There is no way to get a sum of 3.

Example 5:
Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation:
The answer must be returned modulo 10^9 + 7.
*/

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
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
    static constexpr int MOD_CONST = 1000000007;
    int roll(int d, int f, int target) {
        if (d == 1)
            return (target > f) ? 0 : 1;
        if (target == d)
            return 1;

        tuple<int, int> key = make_tuple(d, target);
        auto it = cache.find(key);
        if (it != end(cache))
            return it->second;

        int res = 0;
        for (int i = 1; i <= min(f, target - d + 1); ++i) {
            res = (res + roll(d - 1, f, target - i)) % MOD_CONST;
        }

        return cache[key] = res % MOD_CONST;
    }

    int numRollsToTarget(int d, int f, int target) {
        cache.clear();
        return roll(d, f, target);
    }

    map<tuple<int, int>, int> cache;
};

int main() {
    Solution sol;
    int d, f, target;

    // Expected: 1
    d = 1, f = 6, target = 3;

    // Expected: 6
    // d = 2, f = 6, target = 7;

    // Expected: 1
    d = 2, f = 5, target = 10;

    // Expected: 0
    // d = 1, f = 2, target = 3;

    // Expected: 222616187
    // d = 30, f = 30, target = 500;

    d = 30, f = 30, target = 500;

    cout << "Result: " << sol.numRollsToTarget(d, f, target) << endl;

    return 0;
}
