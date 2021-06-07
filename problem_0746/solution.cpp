/*
746. Min Cost Climbing Stairs
Easy

You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999
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
    vector<int> dp;
    int sz;

    int compute(vector<int>& cost, int index) {
        if (index >= sz)
            return 0;
        int& res = dp[index];
        if (res >= 0)
            return res;
        res = cost[index] + min(compute(cost, index + 1), compute(cost, index + 2));

        return res;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        sz = cost.size();
        dp.resize(sz, -1);
        return min(compute(cost, 0), compute(cost, 1));
    }
};

int main() {
    vector<int> cost;

    // Output: 15
    {
        Solution sol;
        cost = {10,15,20};
        cout << sol.minCostClimbingStairs(cost) << endl;
    }

    // Output: 6
    {
        Solution sol;
        cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        cout << sol.minCostClimbingStairs(cost) << endl;
    }

    return 0;
}
