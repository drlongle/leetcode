/*
1272. Remove Interval
Medium

Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.

We remove the intersections between any interval in intervals and the interval toBeRemoved.

Return a sorted list of intervals after all such removals.

Example 1:
Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
Output: [[0,1],[6,7]]

Example 2:
Input: intervals = [[0,5]], toBeRemoved = [2,3]
Output: [[0,2],[3,5]]

Constraints:
1 <= intervals.length <= 10^4
-10^9 <= intervals[i][0] < intervals[i][1] <= 10^9
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (auto& interval: intervals) {
            if (interval[1] <= toBeRemoved[0] || interval[0] >= toBeRemoved[1])
                res.emplace_back(interval);
            else {
                if (interval[0] < toBeRemoved[0])
                    res.emplace_back(vector<int>{interval[0], toBeRemoved[0]});
                if (interval[1] > toBeRemoved[1])
                    res.emplace_back(vector<int>{toBeRemoved[1], interval[1]});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
