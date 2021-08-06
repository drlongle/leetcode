/*
681. Next Closest Time
Medium

Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits.
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid.
"1:34", "12:9" are all invalid.

Example 1:
Input: time = "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.

Example 2:
Input: time = "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

Constraints:
time.length == 5
time is a valid time in the form "HH:MM".
0 <= HH < 24
0 <= MM < 60
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

class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits{time[0],time[1],time[3],time[4]};
        auto it = digits.upper_bound(time[4]);
        if (it != digits.end()) {
            time[4] = *it;
            return time;
        }

        it = digits. upper_bound(time[3]);
        if ( it != digits. end() && *it <'6'){
            time[3]= *it;
            time[4]=* digits.begin();
            return time;
        }
        it = digits.upper_bound(time[1]);
        if (it != digits.end() && (time[0] < '2' || *it < '4')) {
            time[1] = *it;
            time[3] = time[4] = *digits.begin();
            return time;
        }

        it = digits.upper_bound (time[0]);
        if (it != digits. end() && (*it < '2' || (*it =='2'&& *digits.begin() < '4'))) {
            time[0] = *it;
            time[1] = time[3] = time[4] = *digits.begin();
            return time;
        }

        time[0] = time[1] = time[3] = time[4] = *digits.begin();
        return time;
    }
};

int main() {
    Solution sol;

    return 0;
}
