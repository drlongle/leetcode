/*
906. Super Palindromes
Hard

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers
in the inclusive range [left, right].

Example 1:
Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.

Example 2:
Input: left = "1", right = "2"
Output: 1

Constraints:
1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 10^18].
left is less than or equal to right.
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
    using ll = long long;
    ll lo, hi, res = 0;

    bool palin(ll x) {
        ll reversed = 0, n = x;
        while (n) {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }
        return x == reversed;
    }

    void backtrack (string & s, int i, int j) {
        if (i > j) {
            ll n = stoll(s);
            if (n >= lo && n <= hi)
                res += palin(n*n);
            return;
        }

        for (char ch = (i == 0) ? '1' : '0'; ch <= '9'; ++ch) {
            s[i] = s[j] = ch;
            backtrack (s,i + 1,j - 1);
        }
    }

    int superpalindromesInRange(string left, string right) {
        lo = sqrt(stoll(left)), hi = sqrt(stoll(right));
        int minlen = to_string(lo).size(), maxlen = to_string(hi).size();
        string s;
        for (int len = minlen; len <= maxlen; ++len) {
            s.resize(len);
            backtrack (s, 0, len - 1);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
