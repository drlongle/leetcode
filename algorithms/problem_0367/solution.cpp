/*
367. Valid Perfect Square

Difficulty:Easy
Total Accepted:72.6K
Total Submissions:187.6K

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
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
    bool isPerfectSquare(int num) {
        cout << num << " Test -> " << sqrt(num) << endl;
        if (num == 1) return true;
        if (num < 4) return false;
        int lo = 1, hi = num >> 1;
        while (lo <= hi) {
            ll mid = lo + ((hi - lo) >> 1);
            ll temp = mid*mid;
            if (temp == num) return true;
            else if (temp < num) lo = mid + 1;
            else if (temp < num) lo = mid + 1;
            else hi = mid -1;
        }

        return false;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    int n;

    /*
    n = 2;
    cout << n << " -> " << sol.isPerfectSquare(n) << endl;

    n = 4;
    cout << n << " -> " << sol.isPerfectSquare(n) << endl;

    n = 8;
    cout << n << " -> " << sol.isPerfectSquare(n) << endl;

    n = 9;
    cout << n << " -> " << sol.isPerfectSquare(n) << endl;
    */

    n = 808201;
    cout << n << " -> " << sol.isPerfectSquare(n) << endl;

    return 0;
}

