/*
441. Arranging Coins

Difficulty: Easy

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
0
0 0
0 0

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
0
0 0
0 0 0
0 0

Because the 4th row is incomplete, we return 3.

*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if (!n) return 0;
        ll low = 0, high = n;
        ll ans = 0;
        while (low < high) {
            //cout << low << ", " << high << endl;
            ll mid = low + ((high - low) >> 1);
            ll prod = mid*(mid+1)>>1;
            if (prod > n)
                high = mid-1;
            else if (prod == n)
                return mid;
            else {
                low = mid+1;
                ans = max(ans, mid);
            }
        }
        return ((low*(low+1)>>1) <= n) ? low : ans;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    int n;

    n = 5;
    cout << "n: " << n << " --> " << sol.arrangeCoins(n) << endl;

    n = 8;
    cout << "n: " << n << " --> " << sol.arrangeCoins(n) << endl;

    n = 1804289383;
    cout << "n: " << n << " --> " << sol.arrangeCoins(n) << endl;

    return 0;
}

