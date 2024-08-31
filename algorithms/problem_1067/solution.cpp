/*
1067. Digit Count in Range
Hard

Given a single-digit integer d and two integers low and high, return the number
of times that d occurs as a digit in all integers in the inclusive range [low,
right].

Example 1:
Input: d = 1, low = 1, high = 13
Output: 6
Explanation: The digit d = 1 occurs 6 times in 1, 10, 11, 12, 13.
Note that the digit d = 1 occurs twice in the number 11.

Example 2:
Input: d = 3, low = 100, high = 250
Output: 35
Explanation: The digit d = 3 occurs 35 times in
103,113,123,130,131,...,238,239,243.

Constraints:
0 <= d <= 9
1 <= low <= high <= 2 * 10^8

https://leetcode.com/problems/digit-count-in-range/
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

using namespace std;

class Solution {
  public:
    int count_zeros(int num) {
        int res = 0;
        while (num >= 10) {
            string s = to_string(num);
            int len = s.size();

            res += (s[0] - '0') * (lookup_zero[len - 2] + len - 1);
            int multiply = 0;
            for (int j = 1; j < len - 1; ++j) {
                multiply += pow(10, len - j - 1) - 1;
            }
            res += multiply * (s[0] - '1');
            if (len > 2) {
                if (s[1] == '0') {
                    int i = 1, mult = 0;
                    for (; s[i] == '0' && i < len; ++i) {
                        ++mult;
                    }

                    // For the pattern 10xxx, '0' appears 999 times at the
                    // second digit
                    for (int j = i; j < len - 1; ++j) {
                        res += pow(10, len - j - 1) - 1;
                    }
                    if (i < len)
                        res += stoi(s.substr(i)) * mult;
                } else {
                    for (int j = 2; j < len; ++j) {
                        res += pow(10, len - j) - 1;
                    }
                }
            }
            num %= (int)pow(10, len - 1);
        }
        return res;
    }

    int count(int d, int num) {
        int res = 0;
        while (num >= 10) {
            string s = to_string(num);
            int len = s.size();
            if (s[0] - '0' > d && d > 0)
                res += pow(10, len - 1);

            res += (s[0] - '0') * lookup[len - 2];
            num %= (int)pow(10, len - 1);
            if (s[0] == '0' + d)
                res += num + 1;
        }
        return res + (num >= d);
    }

    vector<long long> lookup{1}, lookup_zero{0};
    Solution() {
        for (int len = 2, pow = 10; len <= 8; ++len, pow *= 10) {
            int num = lookup.back();
            lookup.push_back(10 * num + pow);
        }

        for (int len = 2, pow = 1; len <= 8; ++len, pow *= 10) {
            int num = lookup_zero.back();
            lookup_zero.push_back(num + 9 * pow * (len - 1));
        }
        /*
        copy (begin(lookup_zero), end (lookup_zero), ostream_iterator
        <int>(cout, ", ")); cout << endl;
        */
    }

    int digitsCount(int d, int low, int high) {
        if (d > 0)
            return count(d, high) - count(d, low - 1);
        else
            return count_zeros(high) - count_zeros(low - 1);
    }
};

int run_tests() {
    Solution sol;
    int d, low, high, expected;

    expected = 6;
    d = 1, low = 1, high = 13;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 6 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 35;
    d = 3, low = 100, high = 250;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 35 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 1;
    d = 0, low = 1, high = 10;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 1 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 3;
    d = 0, low = 1, high = 30;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 3 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 4;
    d = 0, low = 1, high = 49;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 4 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 9;
    d = 0, low = 1, high = 99;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 9 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 11;
    d = 0, low = 1, high = 100;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 11 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 25;
    d = 0, low = 1, high = 155;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 25 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 29;
    d = 0, low = 1, high = 199;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 29 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 31;
    d = 0, low = 1, high = 200;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 31 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 36;
    d = 0, low = 1, high = 205;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 36 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 86;
    d = 0, low = 1, high = 467;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 86 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 189;
    d = 0, low = 1, high = 999;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 189 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 192;
    d = 0, low = 1, high = 1000;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 192 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 202;
    d = 0, low = 1, high = 1005;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 202 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 217;
    d = 0, low = 1, high = 1015;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 217 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 236;
    d = 0, low = 1, high = 1032;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 236 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 309;
    d = 0, low = 1, high = 1099;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 311;
    d = 0, low = 1, high = 1100;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 329;
    d = 0, low = 1, high = 1199;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 329 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 489;
    d = 0, low = 1, high = 1999;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 492;
    d = 0, low = 1, high = 2000;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 339;
    d = 0, low = 1080, high = 2160;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 339 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 223;
    d = 0, low = 625, high = 1250;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 223 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 3112;
    d = 0, low = 1, high = 10100;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 4192;
    d = 0, low = 1, high = 11000;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 6893;
    d = 0, low = 1, high = 20000;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == expected ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 189228;
    d = 0, low = 1, high = 400105;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 189228 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    expected = 4825264;
    d = 0, low = 1, high = 8090120;
    cout << "d: " << d << ", low: " << low << ", high: " << high << " -> "
         << sol.digitsCount(d, low, high) << ' '
         << (sol.digitsCount(d, low, high) == 4825264 ? "right" : "wrong")
         << ", expected: " << expected << endl;

    return 0;
}

int main(int argc, const char *argv[]) {
    if (argc == 1)
        run_tests();
    else if (argc == 4) {
        int d = stoi(argv[1]);
        int low = stoi(argv[2]);
        int high = stoi(argv[3]);
        Solution sol;
        std::cout << sol.digitsCount(d, low, high) << std::endl;
    } else {
        std::cerr << "Usage: " << argv[0] << " d low high" << std::endl;
    }
}
