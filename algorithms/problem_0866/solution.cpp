/*
866. Prime Palindrome
Medium

Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1.

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left.

For example, 12321 is a palindrome.

Example 1:
Input: 6
Output: 7

Example 2:
Input: 8
Output: 11

Example 3:
Input: 13
Output: 101

Note:
1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

using namespace std;

class Solution {
public:
    string s;
    int sz;

    bool is_palindrome() {
        int i = sz / 2;
        int j = i + (sz % 2 == 0);
        while (i >= 0) {
            if (s[i--] != s[j++])
                return false;
        }
        return true;
    }

    void fix() {
        bool need_next = false;
        bool inc_mid = false;
        for (int i = 0, j = sz-1; i < j; ++i, --j) {
            if (s[j] > s[i]) {
                if (j > i+1) {
                    s[j] = s[i];
                    need_next = true;
                } else {
                    s[j] = ++s[i];
                    inc_mid = true;
                }
            } else if (s[j] < s[i])
                s[j] = s[i];
        }
        if (need_next && !inc_mid)
            next();
    }

    void next() {
        int i, j;
        if (sz % 2 == 0) {
            i = sz / 2 - 1;
            j = i + 1;
        } else {
            i = j = sz / 2;
        }
        if (s.back() < s[0]) {
            s.back() = s[0];
            if (is_prime())
                return;
        }

        int carry = 1;
        s.back() = s[0];
        while (carry > 0) {
            if (s[j] < s[i]) {
                s[j] = s[i];
                break;
            }
            if (i < 0) {
                s = "1" + string(sz, '0');
                ++sz;
                next();
                return;
            } else {
                if (++s[i] > '9') {
                    s[i] = '0';
                } else
                    carry = 0;
                s[j] = s[i];
            }
            --i, ++j;
        }
    }

    bool is_prime() {
        int n = stoi(s);
        if (n == 1)
            return false;
        int lim = sqrt(n);
        for (int i = 2; i <= lim; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int primePalindrome(int N) {
        s = to_string(N);
        sz = s.size();
        if (!is_palindrome())
            fix();
        while (!is_prime())
            next();

        return stoi(s);
    }
};

int main() {
    Solution sol;
    int n;

    // Output: 7
    n = 6;
    cout << sol.primePalindrome(n) << endl;

    // Output: 11
    n = 8;
    cout << sol.primePalindrome(n) << endl;

    // Output: 101
    n = 13;
    cout << sol.primePalindrome(n) << endl;

    // Output: 10301
    n = 1328;
    cout << sol.primePalindrome(n) << endl;

    // Output:98689
    n = 98390;
    cout << sol.primePalindrome(n) << endl;

    return 0;
}
