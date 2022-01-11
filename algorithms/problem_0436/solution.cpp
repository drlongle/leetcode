/*
436. Find Right Interval

    User Accepted: 298
    User Tried: 375
    Total Accepted: 309
    Total Submissions: 853
    Difficulty: Medium

Given a set of intervals, for each of the interval i, check if there exists an
interval j whose start point is bigger than or equal to the end point of the
interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which
means that the interval j has the minimum start point to build the "right"
relationship for interval i. If the interval j doesn't exist, store -1 for
the interval i. Finally, you need output the stored value of each interval
as an array.

Note:
    You may assume the interval's end point is always bigger than its start
        point.
    You may assume none of these intervals have the same start point.

Example 1:
Input: [ [1,2] ]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:
Input: [ [3,4], [2,3], [1,2] ]
Output: [-1, 0, 1]
Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.

Example 3:
Input: [ [1,4], [2,3], [3,4] ]
Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.

 */

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> lookup;
        for (int i = 0; i < static_cast<int>(intervals.size()); ++i) {
            lookup[intervals[i][0]] = i;
        }
        vector<int> res;
        for (int i = 0; i < static_cast<int>(intervals.size()); ++i) {
            auto it = lookup.lower_bound(intervals[i][1]);
            if (it == end(lookup))
                res.emplace_back(-1);
            else
                res.emplace_back(it->second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;
    
    intervals = {{1,2}};

    intervals = { {3,4}, {2,3}, {1,2} };

    intervals = { {1,4}, {2,3}, {3,4} };
    
    auto res = sol.findRightInterval(intervals);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));

    
    return 0;
}
