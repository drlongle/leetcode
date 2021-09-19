/*
469. Convex Polygon
Medium

You are given an array of points on the X-Y plane points where points[i] = [xi, yi]. The points form a polygon
when joined sequentially.

Return true if this polygon is convex and false otherwise.

You may assume the polygon formed by given points is always a simple polygon. In other words, we ensure that
exactly two edges intersect at each vertex and that edges otherwise don't intersect each other.

Example 1:
Input: points = [[0,0],[0,5],[5,5],[5,0]]
Output: true

Example 2:
Input: points = [[0,0],[0,10],[10,10],[10,0],[5,5]]
Output: false

Constraints:
3 <= points.length <= 10^4
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the given points are unique.
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

class Solution {
public:

    using ll = long long;

    ll product(vector<ll>& v1, vector<ll>& v2) {
        return v1[0] * v2[1] - v1[1] * v2[0];
    }

    bool isConvex(vector<vector<int>>& points) {
        vector<vector<ll>> vect;
        int sz = points.size();
        for (int i = 0; i < sz - 1; ++i) {
            vector<ll> v{points[i+1][0] - points[i][0], points[i+1][1] - points[i][1]};
            vect.push_back(v);
        }

        vector<ll> v{points[0][0] - points[sz-1][0], points[0][1] - points[sz-1][1]};
        vect.push_back(v);

        ll p = product(vect[sz-1], vect[0]);

        for (int i = 0; i < sz - 1; ++i) {
            if (product (vect[i], vect[i+1]) * p < 0)
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
