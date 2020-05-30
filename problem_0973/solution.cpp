/*
973. K Closest Points to Origin
Medium

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)

Note:
1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
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

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto lambda = [] (const pair<int, int>& p1, const pair <int, int>& p2) {
                          double d1 = sqrt(pow(p1.first, 2) + pow(p1.second, 2));
                          double d2 = sqrt(pow(p2.first, 2) + pow(p2.second, 2));
                          return d1 < d2;
                      };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda)> pq(lambda);
        for (auto& point: points) {
            if (pq.size() < K)
                pq.emplace(point[0], point[1]);
            else {
                pair<int, int> p(point[0], point[1]);
                if (lambda(p, pq.top())) {
                    pq.pop();
                    pq.emplace(p);
                }
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            auto& point = pq.top();
            res.emplace_back(vector<int>{point.first, point.second});
            pq.pop();
        }
        
        return res;
    }

    vector<vector<int>> kClosest2(vector<vector<int>>& points, int K) {
        auto lambda = [] (const vector<int>& v1, const vector<int>& v2) {
                          double d1 = sqrt(pow(v1[0], 2) + pow(v1[1], 2));
                          double d2 = sqrt(pow(v2[0], 2) + pow(v2[1], 2));
                          return d1 < d2;
                      };
        sort(begin(points), end(points), lambda);
        points.resize(K);
        return points;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points, res;
    int K;
    
    points = {{1,3},{-2,2}}, K = 1;
    res = sol.kClosest(points, K);
    for (auto& r: res) {
        copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    return 0;
}
