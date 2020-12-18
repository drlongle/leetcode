/*
253. Meeting Rooms II
Medium

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
find the minimum number of conference rooms required.

Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

struct TimePoint {
    bool operator<(TimePoint& other) const {
        return time < other.time || (time == other.time && !start);
    }
    TimePoint(int t, bool s): time(t), start(s) {}
    int time;
    bool start;
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<TimePoint> points;
        for (auto& interval: intervals) {
            points.emplace_back(interval[0], true);
            points.emplace_back(interval[1], false);
        }
        sort(begin(points), end(points));
        int cnt = 0, res = 0;
        for (auto& point: points) {
            if (point.start)
                ++cnt;
            else
                --cnt;
            res = max(res, cnt);
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
