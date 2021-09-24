/*
1888. Minimum Number of Flips to Make the Binary String Alternating
Medium

You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Example 1:
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".

Example 2:
Input: s = "010"
Output: 0
Explanation: The string is already alternating.

Example 3:
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".

Constraints:
1 <= s.length <= 10^5
s[i] is either '0' or '1'.
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
    int minFlips(string s) {
        int sz = s.size(), res = 0;
        vector<int> lfs(sz, 0), rfs(sz, 0);

        char ch = s[0];
        for (int i = 1; i < sz; ++i) {
            lfs[i] = lfs[i-1] + (s[i] == ch);
            ch = '0' + 1 - (ch - '0');
        }

        res = lfs[sz-1];
        ch = s[sz - 1];
        for (int i = sz - 2; i >= 0; --i) {
            rfs[i] = rfs[i+1] + (s[i] == ch);
            ch = '0' + 1 - (ch - '0');
        }

        for (int i = 1; i < sz; ++i) {
            if (s[0] != s.back()) {
                res = min(res, rfs[i] + lfs[i-1]);
                res = min(res, sz - lfs[i-1] - rfs[i]);
            } else {
                res = min(res, rfs[i] + min(lfs[i-1] + i, i - lfs[i-1]));
                res = min(res, lfs[i-1] + sz - i - rfs[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 2
    s = "111000";
    cout << sol.minFlips(s) << endl;

    // Output: 0
    s = "010";
    cout << sol.minFlips(s) << endl;

    // Output: 1
    s = "1110";
    cout << sol.minFlips(s) << endl;

    // Output: 0
    s = "110";
    cout << sol.minFlips(s) << endl;

    // Output: 3
    s = "1111111010";
    cout << sol.minFlips(s) << endl;

    // Output: 2
    s = "01001001101";
    cout << sol.minFlips(s) << endl;

    // Output: 4
    s = "001000000010";
    cout << sol.minFlips(s) << endl;

    // Output: 19
    s = "10111001111010011001011111010110000101011111";
    cout << sol.minFlips(s) << endl;

    // Output: 18
    s = "111000010100100110101011100001000001011100101";
    cout << sol.minFlips(s) << endl;

    // Output: 35
    s = "000110010010011101100011000000100111001010001110000100100100001100010100101010110";
    cout << sol.minFlips(s) << endl;

    return 0;
}
