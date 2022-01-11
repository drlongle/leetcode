/*
265. Paint House II
Hard

There are a row of n houses, each house can be painted with one of the k colors. The cost of
painting each house with a certain color is different. You have to paint all the houses such
that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of
painting house 1 with color 2, and so on...

Return the minimum cost to paint all houses.

Example 1:
Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.

Example 2:
Input: costs = [[1,3],[2,4]]
Output: 5

Constraints:
costs.length == n
costs[i].length == k
1 <= n <= 100
1 <= k <= 20
1 <= costs[i][j] <= 20

Follow up: Could you solve it in O(nk) runtime?
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
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size(), res = INT_MAX;
        vector <vector<int>> dp(n, vector <int>(k));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = costs[i][j];
                if (i > 0) {
                    int add_cost = INT_MAX;
                    for (int x = 1; x < k ; ++x) {
                        add_cost = min(add_cost, dp[i-1][(j+x)%k]);
                    }
                    dp[i][j] += add_cost;
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
