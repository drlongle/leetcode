/*
313. Super Ugly Number
Total Accepted: 12139 Total Submissions: 35961 Difficulty: Medium

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k <= 100, 0 < n <= 10^6, 0 < primes[i] < 1000. 
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

class Compare
{
public:
    bool operator()(const pair<long long, int>& p1,
        const pair<long long, int>& p2) const
    {
        return p1.first < p2.first;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int psize = static_cast<int>(primes.size());
        vector<deque<long long> > uglyNumbers(psize);
        long long ugly = 1;
        for (int i = 0; i < psize; ++i) {
            uglyNumbers[i].emplace_back(primes[i]);
        }

        set<pair<long long, int>, Compare> candidates;
        for (int i = 0; i < psize; ++i) {
            candidates.emplace(make_pair(uglyNumbers[i].front(),i));
        }
        for (int count = 2; count <= n; ++count) {
            pair<long long, int> smallest = *(candidates.begin());
            candidates.erase(smallest);
            ugly = smallest.first;
            int index = smallest.second;
            uglyNumbers[index].pop_front();
            for (int j = index ; j < psize ; ++j) {
                uglyNumbers[j].emplace_back(ugly*primes[j]);
            }
            candidates.emplace(make_pair(uglyNumbers[index].front(),index));
        }

        return static_cast<int>(ugly);
    }

    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        set<long long> candidates;
        candidates.emplace(1);
        for (auto const& p: primes)
            candidates.emplace(p);
        long long ugly = 1;
        for (int i = 1; i <= n; ++i)
        {
            ugly = *(candidates.begin());
            candidates.erase(ugly);
            for (auto const& p: primes) {
                candidates.emplace(ugly*p);
            }
        }

        return static_cast<int>(ugly);
    }
};

int main()
{
    Solution sol;
    vector<int> primes;
    primes = {2, 7, 13, 19};
    for (int i = 1; i < 20; ++i)
        cout << i << " --> " << sol.nthSuperUglyNumber(i, primes) << endl;

    return 0;
}

