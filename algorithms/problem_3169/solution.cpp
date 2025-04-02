/*
3169. Count Days Without Meetings
Medium

You are given a positive integer days representing the total number of days an
employee is available for work (starting from day 1). You are also given a 2D
array meetings of size n where, meetings[i] = [start_i, end_i] represents the
starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings
are scheduled.

Note: The meetings may overlap.

Example 1:
Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
Output: 2
Explanation:
There is no meeting scheduled on the 4th and 8th days.

Example 2:
Input: days = 5, meetings = [[2,4],[1,3]]
Output: 1
Explanation:
There is no meeting scheduled on the 5th day.

Example 3:
Input: days = 6, meetings = [[1,6]]
Output: 0
Explanation:
Meetings are scheduled for all working days.

Constraints:
1 <= days <= 10^9
1 <= meetings.length <= 10^5
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
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
    int countDays(int days, vector<vector<int>> &meetings) {
        vector<pair<int, int>> points;

        for (auto &m : meetings) {
            points.emplace_back(m[0], -m[1]);
        }
        ranges::sort(points);
        int curr = 1, count = 0;
        for (auto [start, end] : points) {
            if (curr < start) {
                count += start - curr;
            }
            curr = max(curr, -end + 1);
        }
        count += max(0, days - curr + 1);
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> meetings;
    int days;

    days = 10, meetings = {{5, 7}, {1, 3}, {9, 10}};
    cout << sol.countDays(days, meetings) << endl;

    days = 5, meetings = {{2, 4}, {1, 3}};
    cout << sol.countDays(days, meetings) << endl;

    days = 6, meetings = {{1, 6}};
    cout << sol.countDays(days, meetings) << endl;

    days = 14;
    meetings = {{6, 11},  {7, 13}, {8, 9},  {5, 8},  {3, 13},
                {11, 13}, {1, 3},  {5, 10}, {8, 13}, {3, 9}};
    cout << sol.countDays(days, meetings) << endl;

    return 0;
}
