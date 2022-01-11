/*
276. Paint Fence
Medium

You are painting a fence of n posts with k different colors. You must paint the posts following these rules:
- Every post must be painted exactly one color.
- At most one pair of adjacent fence posts can have the same color.

Given the two integers n and k, return the number of ways you can paint the fence.

Example 1:
Input: n = 3, k = 2
Output: 6
Explanation: All the possibilities are shown.
Note that painting all the posts red or all the posts green is invalid because there
can only be at most one pair of adjacent posts that are the same color.

Example 2:
Input: n = 1, k = 1
Output: 1

Example 3:
Input: n = 7, k = 2
Output: 42

Constraints:
1 <= n <= 50
1 <= k <= 10^5
The answer is guaranteed to be in the range [0, 2^31 - 1] for the given n and k.
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
    int numWays(int n, int k) {
        int same(0), diff(k);

        for (int i = 2; i <= n; ++i) {
            int ndiff = (same+diff)*(k-1);
            same = diff;
            diff = ndiff;
        }

        return same+diff;
    }
};

int main() {
    Solution sol;

    return 0;
}
