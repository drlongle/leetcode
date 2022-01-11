/*
507. Perfect Number
Easy

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the
number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

Example 1:
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

Example 2:
Input: num = 6
Output: true

Example 3:
Input: num = 496
Output: true

Example 4:
Input: num = 8128
Output: true

Example 5:
Input: num = 2
Output: false

Constraints:
1 <= num <= 10^8
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
    bool checkPerfectNumber(int num) {
        int sum = (num != 1);
        double limit = sqrt(num);
        for (int i = 2; i <= limit; ++i) {
            if (num % i == 0) {
                sum += i;
                if (static_cast<double>(i) != limit)
                    sum += (num / i);
            }
        }

        return sum == num;
    }
};

int main() {
    Solution sol;
    int num;

    // Output: true
    num = 28;
    cout << boolalpha << sol.checkPerfectNumber(num) << endl;

    // Output: true
    num = 6;
    cout << boolalpha << sol.checkPerfectNumber(num) << endl;

    // Output: true
    num = 496;
    cout << boolalpha << sol.checkPerfectNumber(num) << endl;

    // Output: true
    num = 8128;
    cout << boolalpha << sol.checkPerfectNumber(num) << endl;

    // Output: false
    num = 2;
    cout << boolalpha << sol.checkPerfectNumber(num) << endl;

    return 0;
}
