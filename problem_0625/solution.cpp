/*
625. Minimum Factorization
Medium

Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input: 48
Output: 68

Example 2
Input: 15
Output: 35
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<int, long long> dp;
    long long smallestFactorization(int a) {
        if (a < 10)
            return a;
        auto it = dp.find(a);
        if (it != dp.end())
            return it->second;
        long long res = (long long) INT_MAX + 1;
        for (int i = 2; i < 10; ++i) {
            int j = a / i;
            if (i * j == a) {
                long long k = smallestFactorization(j);
                if (!k)
                    continue;
                string si = to_string(i), sj = to_string(k);
                string s = min(si + sj, sj + si);
                res = min(res, stoll(s));
            }
        }

        return dp[a] = res > INT_MAX ? 0 : res;
    }
};

int main() {
    Solution sol;
    int n;

    // Output: 68
    n = 48;
    cout << sol.smallestFactorization(n) << endl;

    // Output: 35
    n = 15;
    cout << sol.smallestFactorization(n) << endl;

    // Output: 288888
    n = 65536;
    cout << sol.smallestFactorization(n) << endl;

    // Output: 0
    n = 10000000;
    cout << sol.smallestFactorization(n) << endl;

    n = 18000000;
    cout << sol.smallestFactorization(n) << endl;

    return 0;
}
