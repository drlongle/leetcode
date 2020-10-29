/*
849. Maximize Distance to Closest Person
Medium

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in
the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
Return that maximum distance to the closest person.

Example 1:
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Example 2:
Input: seats = [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

Example 3:
Input: seats = [0,1]
Output: 1

Constraints:
2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.
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

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int sz = seats.size();
        vector<int> backward(sz), forward(sz);
        for (int i = 0, last = -1; i < sz; ++i) {
            backward[i] = last;
            if (seats[i])
                last = i;
        }

        for (int i = sz-1, last = -1; i >= 0; --i) {
            forward[i] = last;
            if (seats[i])
                last = i;
        }

        int res = 0;
        for (int i = 0; i < sz; ++i) {
            if (seats[i])
                continue;
            int t = numeric_limits<int>::max();
            if (backward[i] >= 0)
                t = i - backward[i];
            if (forward[i] >= 0)
                t = min(t, forward[i] - i);
            res = max(res, t);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> seats;

    // Output: 2
    seats = {1,0,0,0,1,0,1};
    cout << sol.maxDistToClosest(seats) << endl;

    // Output: 3
    seats = {1,0,0,0};
    cout << sol.maxDistToClosest(seats) << endl;

    // Output: 1
    seats = {0,1};
    cout << sol.maxDistToClosest(seats) << endl;

    return 0;
}
