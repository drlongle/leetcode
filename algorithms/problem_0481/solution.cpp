/*
481. Magical String
Medium

A magical string s consists of only '1' and '2' and obeys the following rules:

The string s is magical because concatenating the number of contiguous
occurrences of characters '1' and '2' generates the string s itself. The first
few elements of s is s = "1221121221221121122……". If we group the consecutive
1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the
occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......".
You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the
magical string s.

Example 1:
Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "122112" and it
contains three 1's, so return 3.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 10^5

https://leetcode.com/problems/magical-string/
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    std::vector<char> chars{'1', '2'};
    int count(int i, size_t n) {
        std::string s;
        size_t s_index = 0, c_index = i;
        int res = 0;
        while (s.size() < n) {
            size_t count;
            if (s_index >= s.size())
                count = chars[c_index] - '0';
            else
                count = s[s_index] - '0';
            if (c_index == 0)
                res += min(count, n - s.size());
            s += std::string(count, chars[c_index]);
            c_index = (c_index + 1) % 2;
            ++s_index;
        }

        return res;
    }

    int magicalString(int n) { return count(0, n); }
};

int main() {
    Solution sol;
    int n;

    // Expected: 3
    n = 6;
    cout << n << " -> " << sol.magicalString(n) << std::endl;

    // Expected: 1
    n = 3;
    cout << n << " -> " << sol.magicalString(n) << std::endl;

    // Expected: 2
    n = 4;
    cout << n << " -> " << sol.magicalString(n) << std::endl;

    // Expected: 72
    n = 144;
    cout << n << " -> " << sol.magicalString(n) << std::endl;

    return 0;
}
