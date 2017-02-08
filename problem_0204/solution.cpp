/*
204. Count Primes
Total Accepted: 65020 Total Submissions: 263731 Difficulty: Easy

Description:
Count the number of prime numbers less than a non-negative number, n.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    
    // is_prime[i] indicates whether (i) is prime.
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int count = 0;
        is_prime[0] = false;
        is_prime[1] = false;
        int limit = floor(sqrt(n));
        for (int i = 2; i <= limit; ++i)
        {
            if (is_prime[i])
            {
                int t = i*i;
                while (t < n)
                {
                    is_prime[t] = false;
                    t += i;
                }
            }
        }
        for (const auto& p: is_prime)
            count += p;
        return count;
    }

    
    /*
        Advanced solution: use a bool vector to indicate whether a number
        is prime. is_prime[i] indicates whether (2*i+1) is prime.
     */
    int countPrimes2(int n) {
        if (n <= 2) return 0;
        int array_size = ceil((double (n-1) / 2));
        vector<bool> is_prime(array_size, true);
        int count = 1;
        is_prime[0] = false;
        int limit = ceil(sqrt(n));
        for (int i = 1; i < array_size; ++i)
        {
            int k = (i << 1) + 1;
            if (is_prime[i] && k <= limit)
            {
                int t = k*k;
                while (t < n)
                {
                    if (t & 1)
                        is_prime[(t-1)>>1] = false;
                    t += k;
                }
            }
        }
        for (const auto& p: is_prime)
        {
            if (p) ++count;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int n;
    n = 499979;
    cout << "Result: " << sol.countPrimes(n) << endl;

    return 0;
}

