/*
1175. Prime Arrangements
Easy

Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a
product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation,
but [5,2,3,4,1] is not because the prime number 5 is at index 1.

Example 2:
Input: n = 100
Output: 682289015
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

constexpr int mod_const = 1000000007;

ll factorial(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res = (res * i) % mod_const;
    return res;
}

class Solution {
public:
    int numPrimeArrangements(int n)
    {
        set<int> candidates;
        int primes = 0;
        if (n >= 2)
            candidates.emplace(2);
        for (int i = 3; i <= n; i += 2)
            candidates.emplace(i);
        while (!candidates.empty()) {
            int c = *candidates.begin();
            ++primes;
            for (int t = c; t <= n; t += c)
                candidates.erase(t);
            candidates.erase(c);
        }

        return factorial(primes) * factorial(n - primes) % mod_const;
    }
};

int main()
{
    Solution sol;
    int n;

    // Expected: 12
    n = 5;

    n = 6;
    n = 7;
    n = 8;

    // Output: 682289015
    n = 100;

    cout << "Result: " << sol.numPrimeArrangements(n) << endl;

    return 0;
}
