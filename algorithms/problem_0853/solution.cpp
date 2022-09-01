/*
853. Car Fleet
Medium

There are n cars going to the same destination along a one-lane road. The
destination is target miles away.

You are given two integer array position and speed, both of length n, where
position[i] is the position of the ith car and speed[i] is the speed of the ith
car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and
drive bumper to bumper at the same speed. The faster car will slow down to match
the slower car's speed. The distance between these two cars is ignored (i.e.,
they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same
speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still
be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

Example 1:
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each
other at 12. The car starting at 0 does not catch up to any other car, so it is
a fleet by itself. The cars starting at 5 (speed 1) and 3 (speed 3) become a
fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches
target. Note that no other cars meet these fleets before the destination, so the
answer is 3.

Example 2:
Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation: There is only one car, hence there is only one fleet.

Example 3:
Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:
The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each
other at 4. The fleet moves at speed 2. Then, the fleet (speed 2) and the car
starting at 4 (speed 1) become one fleet, meeting each other at 6. The fleet
moves at speed 1 until it reaches target.

Constraints:
n == position.length == speed.length
1 <= n <= 10^5
0 < target <= 10^6
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 10^6
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int res = 1, sz = speed.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < sz; ++i)
            cars.emplace_back(position[i], speed[i]);
        sort(begin(cars), end(cars),
             [](auto &c1, auto &c2) { return c1.first > c2.first; });

        double duration =
            static_cast<double>(target - cars[0].first) / cars[0].second;
        for (int i = 1; i < sz; ++i) {
            double d =
                static_cast<double>(target - cars[i].first) / cars[i].second;
            if (d > duration) {
                ++res;
                duration = d;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> position, speed;
    int target;

    // Output: 3
    target = 12, position = {10, 8, 0, 5, 3}, speed = {2, 4, 1, 1, 3};
    cout << sol.carFleet(target, position, speed) << endl;

    // Output: 1
    target = 10, position = {3}, speed = {3};
    cout << sol.carFleet(target, position, speed) << endl;

    // Output: 1
    target = 100, position = {0, 2, 4}, speed = {4, 2, 1};
    cout << sol.carFleet(target, position, speed) << endl;

    // Output: 1
    target = 10, position = {4, 6}, speed = {3, 2};
    cout << sol.carFleet(target, position, speed) << endl;
}
