/*
1288. Remove Covered Intervals
Medium

Given a list of intervals, remove all intervals that are covered by another interval in the list.
Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals. 

Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Constraints:
1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
intervals[i] != intervals[j] for all i != j
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        map<int, int> ranges;
        for (auto& interval: intervals) {
            auto it = ranges.lower_bound(interval[0]);
            if (it == ranges.end()) {
                if (!ranges.empty()) {
                    auto it2 = ranges.rbegin();
                    if (it2->first <= interval[0] && it2->second >= interval[1])
                        continue;
                }
                ranges.insert(pair(interval[0], interval[1]));
            } else if (it->first == interval[0]) {
                it->second = max(it->second, interval[1]);
            } else if (it->first > interval[0]) {
                auto it2 = it;
                if (it2 != ranges.begin()) {
                    --it2;
                    if (it2->first <= interval[0] && it2->second >= interval[1])
                        continue;
                }
                while (it != ranges.end() && interval[0] <= it->first && interval[1] >= it->second) {
                    it = ranges.erase(it);
                }
                ranges.insert(pair(interval[0], interval[1]));
            }
        }

        return ranges.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;

    // Output: 2
    intervals = {{1,4},{3,6},{2,8}};

    // Output: 1
    intervals = {{1,4},{2,3}};
    
    cout << "Result: " << sol.removeCoveredIntervals(intervals) << endl;
    return 0;
}
