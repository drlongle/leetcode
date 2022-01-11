/*
1680. Concatenation of Consecutive Binary Numbers
Medium

Given an integer n, return the decimal value of the binary string formed by concatenating
the binary representations of 1 to n in order, modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1.

Example 2:
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.

Example 3:
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 10^9 + 7, the result is 505379714.

Constraints:
1 <= n <= 10^5
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
    pair<int, int> compute(int n) {
        pair<int, int> res{0,0};

        while (n > 0) {
            int i = log2(n);
            res.first = res.first * 2 + 1;
            ++res.second;
            n -= (1 << i);
            for (int j = i-1; j >= 0 && (n & (1 << j)) == 0; --j) {
                res.first = res.first * 2;
                ++res.second;
            }
        }

        return res;
    }

    int concatenatedBinary(int n) {
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            auto p = compute(i);
            res = ((res << p.second) + p.first) % 1000000007;
        }

        return res;
    }
};

int main() {
    Solution sol;

    for (int n = 1; n <= 20; ++n) {
        cout << n << " - > " << sol.concatenatedBinary(n) << endl;
    }

    for (int n: {42904,76963,99999,100000}) {
        cout << n << " -> " << sol.concatenatedBinary(n) << endl;
    }

    return 0;
}
