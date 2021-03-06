/*
1499. Max Value of Equation
Hard

Given an array points containing the coordinates of points on a 2D plane, sorted by the x-values,
where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

Find the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

Example 1:
Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.

Example 2:
Input: points = [[0,0],[3,0],[9,2]], k = 3
Output: 3
Explanation: Only the first two points have an absolute difference of 3 or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.

Constraints:
2 <= points.length <= 10^5
points[i].length == 2
-10^8 <= points[i][0], points[i][1] <= 10^8
0 <= k <= 2 * 10^8
points[i][0] < points[j][0] for all 1 <= i < j <= points.length
xi form a strictly increasing sequence.
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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int res = numeric_limits<int>::min(), sz = points.size();
        for (int i = 0; i < sz; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int yx = y - x;
            while (dq.size()) {
                int index = dq.front();
                int diff = x - points[index][0];
                if (diff > k) {
                    dq.pop_front();
                    continue;
                }
                res = max(res, diff + y + points[index][1]);
                break;
            }
            while (dq.size()) {
                int index = dq.back();
                if (points[index][1] - points[index][0] < yx)
                    dq.pop_back();
                else
                    break;
            }
            dq.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points;
    int k;

    // Output: 4
    points = {{1,3},{2,0},{5,10},{6,-10}}, k = 1;
    cout << sol.findMaxValueOfEquation(points, k) << endl;

    // Output: 3
    points = {{0,0},{3,0},{9,2}}, k = 3;
    cout << sol.findMaxValueOfEquation(points, k) << endl;

    // Output: 26
    points = {{-19,-12},{-5,-18},{2,-2},{10,3},{11,-3},{13,17}}, k = 13;
    cout << sol.findMaxValueOfEquation(points, k) << endl;

    return 0;
}
