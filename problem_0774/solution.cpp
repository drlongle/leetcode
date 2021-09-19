/*
774. Minimize Max Distance to Gas Station
Hard

You are given an integer array stations that represents the positions of the gas stations on the x-axis.
You are also given an integer k.

You should add k new gas stations. You can add the stations anywhere on the x-axis, and not necessarily on an integer position.

Let penalty() be the maximum distance between adjacent gas stations after adding the k new stations.

Return the smallest possible value of penalty(). Answers within 10-6 of the actual answer will be accepted.

Example 1:
Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000

Example 2:
Input: stations = [23,24,36,39,46,56,57,65,84,98], k = 1
Output: 14.00000

Constraints:
10 <= stations.length <= 2000
0 <= stations[i] <= 10^8
stations is sorted in a strictly increasing order.
1 <= k <= 10^6
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
    bool check(vector <int>& stations, int k, double distance) {
        for (int i = 0, sz = stations.size() - 1; i < sz; ++i) {
            double curr = stations[i], next = stations[i+1];
            while (k > 0 && next - curr > distance) {
                int n = (next - curr) / distance;
                n = min(n, k);
                k -= n;
                curr += distance * n;
            }
            if (next - curr > distance)
                return false;
        }

        return true;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0, hi = 0;
        for (int i = 1, sz = stations.size(); i < sz; ++i) {
            double d = stations[i] - stations[i-1];
            hi = max(d, hi);
        }

        while (lo + 1e-6 < hi) {
            auto mid = (lo + hi) / 2;
            if (check (stations, k, mid))
                hi = mid;
            else
                lo = mid;
        }

        return lo;
    }
};

int main() {
    Solution sol;

    return 0;
}
