/*
564. Find the Closest Palindrome
Hard

Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"

Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    string fix(string s) {
        int i, j, sz = s.size();
        if (sz % 2 == 0) {
            i = sz / 2 - 1;
            j = i + 1;
        } else {
            i = j = sz / 2;
        }
        bool need_next = false;
        bool inc_mid = false;
        bool increased = false;
        for (; i >= 0; --i, ++j) {
            if (s[j] > s[i]) {
                if (j > i+1) {
                    s[j] = s[i];
                    if (!increased)
                        need_next = true;
                } else {
                    s[j] = ++s[i];
                    inc_mid = true;
                }
            } else if (s[j] < s[i]) {
                s[j] = s[i];
                increased = true;
            }
        }

        if (need_next && !inc_mid)
            s = next(s);
        return s;
    }

    string next(string s) {
        int i, j, sz = s.size();
        if (sz % 2 == 0) {
            i = sz / 2 - 1;
            j = i + 1;
        } else {
            i = j = sz / 2;
        }

        int carry = 1;
        while (carry > 0) {
            if (i < 0) {
                s = string(sz+1, '0');
                s[0] = s.back() = '1';
                return s;
            } else {
                if (++s[i] > '9') {
                    s[i] = '0';
                } else
                    carry = 0;
                s[j] = s[i];
            }
            --i, ++j;
        }

        return s;
    }

    string prev(string s) {
        int i, j, sz = s.size();
        if (sz % 2 == 0) {
            i = sz / 2 - 1;
            j = i + 1;
        } else {
            i = j = sz / 2;
        }

        int carry = 1;
        while (carry > 0) {
            if (i < 0) {
                return string(sz-1, '9');
            } else {
                --s[i];
                if (i == 0 && s[i] == '0') {
                    if (sz == 1)
                        return "0";
                    return string(sz-1, '9');
                }
                else if (s[i] < '0') {
                    s[i] = '0';
                } else
                    carry = 0;
                s[j] = s[i];
            }
            --i, ++j;
        }

        return s;
    }

    bool is_palindrome(string s) {
        for (int i = 0, j = s.size()-1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    string diff(string a, string b) {
        string s;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (size_t i = 0, carry = 0; i < a.size(); ++i) {
            char ch = a[i] - carry;
            if (i < b.size())
                ch -= b[i] - '0';
            if (ch < '0') {
                ch += 10;
                carry = 1;
            } else
                carry = 0;
            s.push_back(ch);
        }
        while (s.size() && s.back() == '0')
            s.pop_back();
        reverse(s.begin(), s.end());

        return s;
    }

    string nearestPalindromic(string s) {
        string n, p;
        if (!is_palindrome(s)) {
            n = fix(s);
            p = prev(n);
        } else {
            n = next(s);
            p = prev(s);
        }

        string dn = diff(n, s);
        string dp = diff(s, p);
        while (dn.size() != dp.size()) {
            if (dn.size() < dp.size())
                dn.insert(dn.begin(), '0');
            else
                dp.insert(dp.begin(), '0');
        }
        cout << "next: " << n << ", dn: " << dn << ", prev: " << p << ", dp: " << dp << endl;

        return dp <= dn ? p : n;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "7"
    s = "8";
    cout << sol.nearestPalindromic(s) << endl;

    // Output: "8"
    s = "9";
    cout << sol.nearestPalindromic(s) << endl;

    // Output: "121"
    s = "123";
    cout << sol.nearestPalindromic(s) << endl;

    // Output: "1221"
    s = "1213";
    cout << sol.nearestPalindromic(s) << endl;

    // "849683515386948"
    s = "849683513624624";
    cout << sol.nearestPalindromic(s) << endl;

    // "9"
    s = "10";
    cout << sol.nearestPalindromic(s) << endl;

    // Output: 0
    s = "1";
    cout << sol.nearestPalindromic(s) << endl;

    // Output: 9
    s = "11";
    cout << sol.nearestPalindromic(s) << endl;

    return 0;
}
