/*
902. Numbers At Most N Given Digit Set
Hard

Given an array of digits, you can write numbers using each digits[i] as many times as we want.
For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

Example 1:
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation:
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.

Example 2:
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation:
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.

Example 3:
Input: digits = ["7"], n = 8
Output: 1

Constraints:
1 <= digits.length <= 9
digits[i].length == 1
digits[i] is a digit from '1' to '9'.
All the values in digits are unique.
1 <= n <= 109
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

    vector<int> pow;
    string limit;

    int count(vector<string>& digits, string& s) {
        size_t sz = s.size();
        int cmp = s.compare(0, sz, limit, 0, sz);
        if (cmp > 0)
            return 0;
        if (cmp < 0)
            return pow[limit.size() - sz];
        if (limit.size() == sz)
            return 1;
        int cnt = 0;
        for (auto& digit: digits) {
            s.push_back(digit[0]);
            cnt += count(digits, s);
            s.pop_back();
        }

        return cnt;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        limit = to_string(n);
        int cnt = 0;
        pow.clear();
        pow.push_back(1);
        for (size_t i = 1; i < limit.size(); ++i) {
            pow.push_back(pow.back() * digits.size());
            cnt += pow.back();
        }

        for (auto digit: digits) {
            cnt += count(digits, digit);
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<string> digits;
    int n;

    // Output: 20
    digits = {"1","3","5","7"}, n = 100;
    cout << sol.atMostNGivenDigitSet(digits, n) << endl;

    // Output: 29523
    digits = {"1","4","9"}, n = 1000000000;
    cout << sol.atMostNGivenDigitSet(digits, n) << endl;

    // Output: 1
    digits = {"7"}, n = 8;
    cout << sol.atMostNGivenDigitSet(digits, n) << endl;

    // Output: 12255070
    digits = {"1","2","3","4","6","7","8","9"}, n = 67688637;
    cout << sol.atMostNGivenDigitSet(digits, n) << endl;

    return 0;
}
