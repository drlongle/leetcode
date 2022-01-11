/*
256. Paint House
Medium

There is a row of n houses, where each house can be painted one of three colors: red, blue, or green.
The cost of painting each house with a certain color is different. You have to paint all the houses
such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost
of painting house 1 with color green, and so on... Return the minimum cost to paint all houses.

Example 1:
Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.

Example 2:
Input: costs = [[7,6,2]]
Output: 2

Constraints:
costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20
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
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), res = INT_MAX;
        vector <vector<int>> dp(n, vector <int>(3));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = costs[i][j];
                if (i > 0) {
                    dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
                }
                if (i == n-1) {
                    res = min(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
