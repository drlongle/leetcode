/*
1573. Number of Ways to Split a String
Medium

Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty
strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"

Example 2:
Input: s = "1001"
Output: 0

Example 3:
Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"

Example 4:
Input: s = "100100010100110"
Output: 12

Constraints:
3 <= s.length <= 10^5
s[i] is '0' or '1'.
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
    int count_zeros(long long n) {
        return ((n - 2) * (n - 1) - (n-2) * (n-1) / 2) % 1000000007;

        /*
        long long res = 0;
        for (int i = 1; i <= n-2; ++i) {
            res += (n - i - 1);
        }

        return res % 1000000007;
        */
    }

    int numWays(string s) {
        int total = 0, sz = s.size();
        map<int, int> pos;

        for (int i = 0; i < sz; ++i) {
            total += (s[i] == '1');
            pos.emplace(total, i);
        }

        if (total % 3 != 0)
            return 0;
        if (total == 0)
            return count_zeros(sz);

        int a1 = pos.lower_bound(total / 3)->second;
        int a2 = pos.upper_bound(total / 3)->second;
        long long a = a2 - a1;
        int b1 = pos.lower_bound(2 * total / 3)->second;
        int b2 = pos.upper_bound(2 * total / 3)->second;
        long long b = b2 - b1;

        return a * b % 1000000007;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 4
    s = "10101";
    cout << sol.numWays(s) << endl;

    // Output: 0
    s = "1001";
    cout << sol.numWays(s) << endl;

    // Output: 3
    s = "0000";
    cout << sol.numWays(s) << endl;

    // Output: 12
    s = "100100010100110";
    cout << sol.numWays(s) << endl;

    return 0;
}
