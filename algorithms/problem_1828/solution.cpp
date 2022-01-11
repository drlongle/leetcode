/*
1828. Queries on Number of Points Inside a Circle
Medium

You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane.
Multiple points can have the same coordinates.

You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj)
with a radius of rj.

For each query queries[j], compute the number of points inside the jth circle. Points on the
border of the circle are considered inside.

Return an array answer, where answer[j] is the answer to the jth query.

Example 1:
Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.

Example 2:
Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
Output: [2,3,2,4]
Explanation: The points and circles are shown above.
queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.

Constraints:
1 <= points.length <= 500
points[i].length == 2
0 <= xi, yi <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= xj, yj <= 500
1 <= rj <= 500
All coordinates are integers.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int xc = queries[i][0], yc = queries[i][1], r = queries[i][2], cnt = 0;
            for (auto& point: points) {
                double d = hypot(xc - point[0], yc - point[1]);
                cnt += (d <= r);
            }
            res[i] = cnt;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points, queries;
    vector<int> res;

    points = {{1,3},{3,3},{5,3},{2,2}}, queries = {{2,3,1},{4,3,1},{1,1,2}};
    res = sol.countPoints(points, queries);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    points = {{1,1},{2,2},{3,3},{4,4},{5,5}}, queries = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
    res = sol.countPoints(points, queries);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
