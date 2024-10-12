/*
2406. Divide Intervals Into Minimum Number of Groups
Medium

You are given a 2D integer array intervals where intervals[i] = [lefti, righti]
represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval
is in exactly one group, and no two intervals that are in the same group
intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For
example, the intervals [1, 5] and [5, 8] intersect.

Example 1:
Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than
3 groups.

Example 2:
Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one
group.

Constraints:
1 <= intervals.length <= 10^5
intervals[i].length == 2
1 <= lefti <= righti <= 10^6
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
    int minGroups(vector<vector<int>> &intervals) {
        ranges::sort(intervals);
        multiset<int> groups;
        for (auto &i : intervals) {
            if (!groups.empty() && *groups.begin() < i[0]) {
                groups.erase(groups.begin());
            }
            groups.insert(i[1]);
        }

        return groups.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;

    intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << sol.minGroups(intervals) << endl;

    intervals = {{1, 3}, {5, 6}, {8, 10}, {11, 13}};
    cout << sol.minGroups(intervals) << endl;

    intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}, {4, 7}};
    cout << sol.minGroups(intervals) << endl;

    return 0;
}
