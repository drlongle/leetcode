/*
264. Ugly Number II
Total Accepted: 27922 Total Submissions: 100805 Difficulty: Medium

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number. 
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

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> candidates;
        candidates.emplace(1);
        long long ugly = 1;
        for (int i = 1; i <= n; ++i)
        {
            ugly = *(candidates.begin());
            candidates.erase(ugly);
            candidates.emplace(ugly*2);
            candidates.emplace(ugly*3);
            candidates.emplace(ugly*5);
        }
        return ugly;
    }
};

int main()
{
    Solution sol;
    int input;
    input = 1407;
    //Expected: 536870912
    cout << input << " -> " << sol.nthUglyNumber(input) << endl;

    return 0;
}

