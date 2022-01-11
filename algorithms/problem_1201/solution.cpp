/*
1201. Ugly Number III
Medium

Write a program to find the n-th ugly number.

Ugly numbers are positive integers which are divisible by a or b or c.

Example 1:
Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Example 2:
Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.

Example 3:
Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.

Example 4:
Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984
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

class Solution {
public:
    using ll = long long;
    ll gcd(int x, int y) {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    
    ll lcm(ll x, ll y) {
        return x * y / gcd(x, y);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ca = lcm(c, a);
        ll abc = lcm(a, bc);

        ll left = 1, right = 2000000000;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            int count = mid / a + mid / b + mid / c - (mid / ab + mid / bc + mid / ca) + mid / abc;

            if (count == n) {
                if (mid % a == 0 || mid % b == 0 || mid % c == 0)
                    return mid;
                else
                    right = mid - 1;
            }
            if (count < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    int a, b, c, n;

    // Output: 4
    n = 3, a = 2, b = 3, c = 5;

    // Output: 6
    //n = 4, a = 2, b = 3, c = 4;

    // Output: 10
    //n = 5, a = 2, b = 11, c = 13;

    // Output: 1999999984
    //n = 1000000000, a = 2, b = 217983653, c = 336916467;

    // Output: 8
    //n = 5, a = 2, b = 3, c = 3;

    // Output: 6
    n = 6, a = 2, b = 1, c = 3;

    // Output: 44
    //n = 25, a = 2, b = 4, c = 7;

    // Output: 2000000000
    //n = 1000000000, a = 2, b = 740091218, c = 473796308;

    // Output: 1999999990
    //n = 1000000000, a = 2, b = 216037921, c = 382899298;
    
    cout << "Result: " << sol.nthUglyNumber(n, a, b, c) << endl;
    
    return 0;
}
