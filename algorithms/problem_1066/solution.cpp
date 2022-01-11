/*
1066. Campus Bikes II
Medium

On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M.
Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker
and their assigned bike is minimized.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

Example 1:
Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation:
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.

Example 2:
Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4
Explanation:
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.

Example 3:
Input: workers = [[0,0],[1,0],[2,0],[3,0],[4,0]], bikes = [[0,999],[1,999],[2,999],[3,999],[4,999]]
Output: 4995

Constraints:
N == workers.length
M == bikes.length
1 <= N <= M <= 10
workers[i].length == 2
bikes[i].length == 2
0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
All the workers and the bikes locations are unique.
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
    int n, m;
    vector <vector <int>> dp;

    int compute(vector<vector<int>>& workers,  vector<vector<int>>& bikes, int wmask, int bmask) {
        if (wmask == 0) return 0;
        auto& res = dp[wmask][bmask];
        if (res > 0)
            return res;
        res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if ((wmask & (1 << i)) == 0)
                continue;
            for (int j = 0; j < m; ++j) {
                if (bmask & (1 << j)) {
                    int dist = abs(workers[i][0]- bikes[j][0]) + abs(workers[i][1]- bikes[j][1]);
                    res = min(res, dist + compute(workers, bikes, wmask ^ (1 << i), bmask ^ (1 << j)));
                }
            }
        }

        return res;
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n = workers.size(), m = bikes.size();
        int wmask = (1 << n) - 1, bmask = (1 << m) - 1;
        dp.resize(wmask + 1,vector <int>(bmask + 1, 0));
        return compute(workers, bikes, wmask, bmask);
    }
};

int main() {
    Solution sol;

    return 0;
}
