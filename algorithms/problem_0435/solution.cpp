/*
435. Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need
to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

Example 2:
Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals
non-overlapping.

Example 3:
Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already
non-overlapping.

Note:
    You may assume the interval's end point is always bigger than its start
point. Intervals like [1,2] and [2,3] have borders "touching" but they don't
overlap each other.

Constraints:
1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4
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
#include <ranges>
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
  static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
      if (intervals.empty())
          return 0;

      ranges::sort(intervals, cmp);

      int count = 0;
      vector<int> prev = intervals[0];
      for (size_t i = 1; i < intervals.size(); ++i) {
          if (prev[1] <= intervals[i][0])
              prev = intervals[i];
          else
              ++count;
      }

      return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;

    // Output: 1
    intervals = {{1,2},{2,3},{3,4},{1,3}};
    
    // Output: 2
    //intervals = {{1,2},{1,2},{1,2}};
    
    // Output: 0
    //intervals = {{1,2},{2,3}};
    
    // Output: 0
    //intervals = {};

    // Output: 4
    intervals = {{0,2},{1,3},{1,3},{2,4},{3,5},{3,5},{4,6}};

    cout << "Result: " << sol.eraseOverlapIntervals(intervals) << endl;
    
    return 0;
}
