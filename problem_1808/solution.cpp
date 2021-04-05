/*
1808. Maximize Number of Nice Divisors
Hard

You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies
the following conditions:

The number of prime factors of n (not necessarily distinct) is at most primeFactors.
The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible
by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3],
then 6 and 12 are nice divisors, while 3 and 4 are not.

Return the number of nice divisors of n. Since that number can be too large, return it modulo 10^9 + 7.

Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers.
The prime factors of a number n is a list of prime numbers such that their product equals n.

Example 1:
Input: primeFactors = 5
Output: 6
Explanation: 200 is a valid value of n.
It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
There is not other value of n that has at most 5 prime factors and more nice divisors.

Example 2:
Input: primeFactors = 8
Output: 18

Constraints:
1 <= primeFactors <= 10^9
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
    static constexpr long long MOD= 1e9+7;
    unordered_map<int, long long> dp;

    long long power(int k, int n){
        if(n==1) return k;
        auto it = dp.find(n);
        if (it != dp.end())
            return it->second;
        return dp[n] = (n&1) ? k*power(k, n/2)*power(k, n/2) % MOD : power(k,n/2)*power(k,n/2) % MOD;
    }

    int maxNiceDivisors (int n) {
        if (n <= 4)
            return n;
        long res =3, num=3;

        int d = (n-4-num) / 3;
        if (d > 0) {
            num += 3*d;
            res = (res* power(3,d)) % MOD;
        }

        while (num+3 <=n) {
            if (num+4==n) {
                num+=4;
                res=res*4%MOD;
            } else {
                res = 3*res%MOD;
                num += 3;
            }
        }

        return (num+2 == n) ? res*2 %MOD : res;
    }
};

int main() {
    Solution sol;
    int n;

    n = 5;
    cout << n << " -> " << sol.maxNiceDivisors(n) << endl;

    n = 8;
    cout << n << " -> " << sol.maxNiceDivisors(n) << endl;

    return 0;
}
