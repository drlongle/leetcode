/*
759. Employee Free Time
Hard

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals,
not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0]
is not defined). Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]

Constraints:
1 <= schedule.length , schedule[i].length <= 50
0 <= schedule[i].start < schedule[i].end <= 10^8
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

#define for_loop(n) for(int i = 0; i < n; ++i)

class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    struct Event {
        int time, delta;
        Event(int t, int d): time(t), delta(d) {}
        bool operator <(const Event& other) const {
            return time < other.time;
        }
    };

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Event> tp;
        for (auto& s: schedule) {
            for (auto& i: s) {
                tp.emplace_back(i.start, 1);
                tp.emplace_back(i.end, -1);
            }
        }
        sort(begin(tp), end(tp));
        vector<Interval> res;
        int cnt = 0, i = 0, sz = tp.size(), prev = -1;
        while (i < sz) {
            int curr = tp[i].time;
            if (prev != -1 && !cnt)
                res.emplace_back(prev, curr);
            for (; i < sz && tp[i].time == curr; ++i) {
                cnt += tp[i].delta;
            }
            prev = curr;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
