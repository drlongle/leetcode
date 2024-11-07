/*
2275. Largest Combination With Bitwise AND Greater Than Zero
Medium

The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND
of every combination of numbers of candidates. Each number in candidates may
only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND
greater than 0.

Example 1:
Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 &
24 = 16 > 0. The size of the combination is 4. It can be shown that no
combination with a size greater than 4 has a bitwise AND greater than 0. Note
that more than one combination may have the largest size. For example, the
combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.

Example 2:
Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.

Constraints:
1 <= candidates.length <= 10^5
1 <= candidates[i] <= 10^7
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
    int largestCombination(vector<int> &candidates) {
        int res = 0;
        const int max_value = 10e7;
        const int max_bit = log2(max_value);
        for (int i = 0; i <= max_bit; ++i) {
            int cnt = 0;
            for (int n : candidates) {
                if (n & (1 << i))
                    ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};

int main() { return 0; }
