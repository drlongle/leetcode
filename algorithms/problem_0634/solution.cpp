/*
634. Find the Derangement of An Array
Medium

In combinatorial mathematics, a derangement is a permutation of the elements of a set,
such that no element appears in its original position.

See https://en.wikipedia.org/wiki/Derangement

You are given an integer n. There is originally an array consisting of n integers from 1 to n in ascending order,
return the number of derangements it can generate. Since the answer may be huge, return it modulo 10^9 + 7.

Example 1:
Input: n = 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].

Example 2:
Input: n = 2
Output: 1

Constraints:
1 <= n <= 10^6
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    using ll = long long;
    vector <ll> dp;
    int mod = 1000000007;

    ll compute(int n) {
        if (n <= 1) return 0;
        if (n == 2) return 1;

        // if we have an array [1,2,3,4,5], then [2,3,4,5] can take the
        // place of 1 and we need to call complete() to find a new place
        // for 1.
        return (n-1) * complete(n-1) % mod;
    }

    // If we have [1,2,3,4,5] and 5 takes the place of 1.
    // complete() finds the number of combinations for
    // [2,3,4, ] where we need to find a new place for 1.
    // There are two possibilities
    // 1 can take the empty place and recursively call compute()
    // 1 can take the place of 2,3,4 and recursively call complete()
    ll complete(int n) {
        if (n<=1) return n;
        if (n==2) return 1;
        ll& res = dp[n];
        if (res) return res;
        res = compute(n-1);
        res = (res + (n-1)*complete(n-1)) % mod;
        return res;
    }

    int findDerangement(int n) {
        dp.resize(n+1,0);
        return compute(n);
    }
};

int main() {
    Solution sol;

    return 0;
}
