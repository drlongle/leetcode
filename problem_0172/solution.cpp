/*
172. Factorial Trailing Zeroes
Total Accepted: 61272 Total Submissions: 184626 Difficulty: Easy

Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0)
        {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    return 0;
}

