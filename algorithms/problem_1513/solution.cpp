/*
1513. Number of Substrings With Only 1s
Medium

Given a binary string s (a string consisting only of '0' and '1's).

Return the number of substrings with all characters 1's.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.

Example 2:
Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.

Example 3:
Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.

Example 4:
Input: s = "000"
Output: 0

Constraints:
s[i] == '0' or s[i] == '1'
1 <= s.length <= 10^5
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
    static constexpr int MOD = 1000000007;
    int numSub(string s) {
        int sz = s.size(), head = 0, tail = 0, res = 0;
        while (head < sz) {
            while (head < sz) {
                if (s[head] == '1')
                    break;
                ++head;
            }
            tail = head;
            while (head < sz) {
                if (s[head] == '0') {
                    break;
                }
                ++head;
            }
            int len = head - tail;
            for (int l = 1; l <= len; ++l) {
                res = (res + (len-l+1)) % MOD;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    s = "0110111";
    cout << sol.numSub(s) << endl;

    s = "101";
    cout << sol.numSub(s) << endl;

    s = "111111";
    cout << sol.numSub(s) << endl;

    return 0;
}
