/*
2220. Minimum Bit Flips to Convert Number
Easy

A bit flip of a number x is choosing a bit in the binary representation of x and
flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any
bit (including any leading zeros not shown) and flip it. We can flip the first
bit from the right to get 110, flip the second bit from the right to get 101,
flip the fifth bit from the right (a leading zero) to get 10111, etc. Given two
integers start and goal, return the minimum number of bit flips to convert start
to goal.

Example 1:
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111
respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we
return 3.

Example 2:
Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively.
We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we
return 3.

Constraints:
0 <= start, goal <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for (int i = 0, n = sizeof(int) * 8; i < n; ++i) {
            int shifted = 1 << i;
            if ((start & shifted) ^ (goal & shifted))
                ++cnt;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    int start, goal;

    start = 10, goal = 7;
    cout << sol.minBitFlips(start, goal) << endl;

    start = 3, goal = 4;

    return 0;
}
