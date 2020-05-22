/*
1453. Maximum Number of Darts Inside of a Circular Dartboard
Hard

You have a very large square wall and a circular dartboard placed on the wall. You have been challenged to throw darts into the board blindfolded. Darts thrown at the wall are represented as an array of points on a 2D plane. 

Return the maximum number of points that are within or lie on any circular dartboard of radius r.

Example 1:
Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
Output: 4
Explanation: Circle dartboard with center in (0,0) and radius = 2 contain all points.

Example 2:
Input: points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
Output: 5
Explanation: Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).

Example 3:
Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
Output: 1

Example 4:
Input: points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
Output: 4

Constraints:
1 <= points.length <= 100
points[i].length == 2
-10^4 <= points[i][0], points[i][1] <= 10^4
1 <= r <= 5000
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

#define ll long long
#define ull unsigned long long

/*
POJ: http://poj.org/problem?id=1981
StackOverflow: https://stackoverflow.com/questions/3229459/algorithm-to-cover-maximal-number-of-points-with-one-circle-of-given-radius/3229582#3229582
LeetCode: https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636372/JavaC%2B%2BPython-POJ-1981

Basic observations :
- I assume the radius is one, since it doesn't change anything.
- given any two points, there exists at most two unit circles on which they lie.
- given a solution circle to your problem, you can move it until it contains two points of your set while keeping the same number of points of your set inside it.

The algorithm is then:
- For each pair of points, if their distance is < 2, compute the two unit circles C1 and C2 that pass through them.
- Compute the number of points of your set inside C1 and C2
- Take the max.
*/

class Solution {
public:
    int calc(int i1, int i2, vector<vector<int>>& points, int r) {
        double x1 = points[i1][0], y1 = points[i1][1], x2 = points[i2][0], y2 = points[i2][1];
        double d = ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) / 4.0;
        if (d > r2)
            return 0;
        double x0 = (x1 + x2) / 2.0 + (y2 - y1) * sqrt(r * r - d) / sqrt(d * 4);
        double y0 = (y1 + y2) / 2.0 - (x2 - x1) * sqrt(r * r - d) / sqrt(d * 4);
        
        int ans = 0;
        for (auto& point: points) {
            int x = point[0], y = point[1];
            ans += ((x-x0)*(x-x0) + (y-y0)*(y-y0) <= r2 + 0.00001);
        }

        return ans;
    }

    double r2;
    int numPoints(vector<vector<int>>& points, int r) {
        r2 = r*r;
        int n = points.size(), ans = 1;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                ans = max(ans, calc(i, j, points, r));
            }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points;
    int r;

    // Output: 4
    points = {{-2,0},{2,0},{0,2},{0,-2}}, r = 2;
    cout << sol.numPoints(points, r) << endl;
    
    // Output: 5
    points = {{-3,0},{3,0},{2,6},{5,4},{0,9},{7,8}}, r = 5;
    cout << sol.numPoints(points, r) << endl;
    
    // Output: 1
    points = {{-2,0},{2,0},{0,2},{0,-2}}, r = 1;
    cout << sol.numPoints(points, r) << endl;
    
    // Output: 4
    points = {{1,2},{3,5},{1,-1},{2,3},{4,1},{1,3}}, r = 2;
    cout << sol.numPoints(points, r) << endl;

    // Output: 5
    points = {{5,5},{-2,5},{4,2},{1,-1},{1,1}}, r = 5;
    cout << sol.numPoints(points, r) << endl;
    
    return 0;
}
