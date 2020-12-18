/*
252. Meeting Rooms
Easy

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if
a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: true

Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti < endi <= 10^6
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto lambda = [] (auto& i1, auto& i2) {
            return i1[0] < i2[0] || (i1[0] == i2[0] && i1[1] < i2[1]);
        };
        sort(begin(intervals), end(intervals), lambda);
        for (size_t n = intervals.size(), i = 1; i < n; ++i) {
            if (intervals[i][0] < intervals[i-1][1])
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
