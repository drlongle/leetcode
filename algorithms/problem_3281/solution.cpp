/*
3281. Maximize Score of Numbers in Ranges
Medium

You are given an array of integers start and an integer d, representing n
intervals [start[i], start[i] + d].

You are asked to choose n integers where the ith integer must belong to the ith
interval. The score of the chosen integers is defined as the minimum absolute
difference between any two integers that have been chosen.

Return the maximum possible score of the chosen integers.

Example 1:
Input: start = [6,0,3], d = 2
Output: 4
Explanation:
The maximum possible score can be obtained by choosing integers: 8, 0, and 4.
The score of these chosen integers is min(|8 - 0|, |8 - 4|, |0 - 4|) which
equals 4.

Example 2:
Input: start = [2,6,13,13], d = 5
Output: 5
Explanation:
The maximum possible score can be obtained by choosing integers: 2, 7, 13,
and 18. The score of these chosen integers is min(|2 - 7|, |2 - 13|, |2 - 18|,
|7 - 13|, |7 - 18|, |13 - 18|) which equals 5.

Constraints:
2 <= start.length <= 10^5
0 <= start[i] <= 10^9
0 <= d <= 10^9
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

/*
If we sort our intervals, points that we pick will be non-decreasing.

With that, we can check in O(n) whether it is possible to pick all points while
maintaining some minimal distance m.

Thus, we binary-search for the maximum m.
 */

class Solution {
  public:
    int maxPossibleScore(vector<int> &start, int d) {
        ranges::sort(start);
        long long lo = 0, hi = start[1] - start[0] + d, res = 0,
                  sz = start.size();
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long point = start[0];
            int i = 1;
            for (; i < sz; ++i) {
                point = max(point + mid, (long long)start[i]);
                if (point > start[i] + d)
                    break;
            }
            if (i == sz) {
                res = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> start;
    int d;

    // Expected: 4
    start = {6, 0, 3}, d = 2;
    // cout << sol.maxPossibleScore(start, d) << endl;

    // Expected: 5
    start = {2, 6, 13, 13}, d = 5;
    // cout << sol.maxPossibleScore(start, d) << endl;

    // Expected: 1109
    start = {100, 1000000000, 0}, d = 1009;
    // cout << sol.maxPossibleScore(start, d) << endl;

    // Expected: 2
    start = {2, 0, 0, 8}, d = 2;
    // cout << sol.maxPossibleScore(start, d) << endl;

    // Expected: 2
    start = {3, 2, 9, 2, 0}, d = 3;
    cout << sol.maxPossibleScore(start, d) << endl;

    return 0;
}
