/*
1776. Car Fleet II
Hard

There are n cars traveling at different speeds in the same direction along a
one-lane road. You are given an array cars of length n, where cars[i] =
[positioni, speedi] represents:

positioni is the distance between the ith car and the beginning of the road in
meters. It is guaranteed that positioni < positioni+1. speedi is the initial
speed of the ith car in meters per second. For simplicity, cars can be
considered as points moving along the number line. Two cars collide when they
occupy the same position. Once a car collides with another car, they unite and
form a single car fleet. The cars in the formed fleet will have the same
position and the same speed, which is the initial speed of the slowest car in
the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the
ith car collides with the next car, or -1 if the car does not collide with the
next car. Answers within 10-5 of the actual answers are accepted.

Example 1:
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the
second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the
third car will collide with the fourth car, and form a car fleet with speed 2
m/s.

Example 2:

Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]


Constraints:
1 <= cars.length <= 10^5
1 <= positioni, speedi <= 10^6
position(i) < position(i+1)

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

class Solution {
  public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        multimap<double, pair<int, int>> pq;
        int sz = cars.size();
        vector<double> res(sz, -1);
        vector<multimap<double, pair<int, int>>::iterator> its(sz, pq.end());
        for (int i = sz - 2; i >= 0; --i) {
            double diff = cars[i][1] - cars[i + 1][1];
            if (diff > 0) {
                double d = (cars[i + 1][0] - cars[i][0]) / diff;
                its[i] = pq.emplace(d, make_pair(i, i + 1));
            }
        }

        while (!pq.empty()) {
            auto it = pq.begin();
            int i = it->second.first;
            int k = it->second.second;
            res[i] = it->first;
            pq.erase(it);

            if (i > 0) {
                cars[i] = cars[k];
                int j = i - 1;
                while (j >= 0) {
                    if (res[j] < 0)
                        break;
                    --j;
                }

                if (j >= 0) {
                    double diff = cars[j][1] - cars[i][1];
                    if (diff > 0) {
                        double d = (cars[i][0] - cars[j][0]) / diff;
                        if (its[j] != pq.end())
                            pq.erase(its[j]);
                        its[j] = pq.emplace(d, make_pair(j, i));
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> cars;
    vector<double> collisionTimes;

    // Output: {1.00000,-1.00000,3.00000,-1.00000}
    /*
    cars = {{1, 2}, {2, 1}, {4, 3}, {7, 2}};
    collisionTimes = sol.getCollisionTimes(cars);
    copy(begin(collisionTimes), end(collisionTimes),
         ostream_iterator<double>(cout, ", "));
    cout << endl;
    */

    // Output: {2.00000,1.00000,1.50000,-1.00000}
    /*
    cars = {{3, 4}, {5, 4}, {6, 3}, {9, 1}};
    collisionTimes = sol.getCollisionTimes(cars);
    copy(begin(collisionTimes), end(collisionTimes),
         ostream_iterator<double>(cout, ", "));
    cout << endl;
    */

    /*
    cars = {{3, 4}, {4, 3}, {6, 4}, {9, 1}, {15, 4}, {17, 1}};
    collisionTimes = sol.getCollisionTimes(cars);
    copy(begin(collisionTimes), end(collisionTimes),
         ostream_iterator<double>(cout, ", "));
    cout << endl;
    */

    // Output:
    // [4.25000,3.00000,2.75000,0.50000,1.50000,0.66667,0.25000,-1.00000,-1.00000,-1.00000]
    cars = {{1, 5},  {6, 5},  {7, 5},  {14, 5}, {15, 3},
            {16, 4}, {17, 5}, {18, 1}, {19, 2}, {20, 2}};
    collisionTimes = sol.getCollisionTimes(cars);
    copy(begin(collisionTimes), end(collisionTimes),
         ostream_iterator<double>(cout, ", "));
    cout << endl;
}
