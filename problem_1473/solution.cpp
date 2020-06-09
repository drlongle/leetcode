/*
1473. Paint House III
Hard

There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that has been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color. (For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods  [{1}, {2,2}, {3,3}, {2}, {1,1}]).

Given an array houses, an m * n matrix cost and an integer target where:

houses[i]: is the color of the house i, 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j+1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods, if not possible return -1.

Example 1:
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

Example 2:
Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
Cost of paint the first and last house (10 + 1) = 11.

Example 3:
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
Output: 5

Example 4:
Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.

Constraints:
m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 10^4
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
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<int>> v(n+1, vector<int>(target+1, numeric_limits<int>::max()));
        vector<vector<vector<int>>> dp(m, v);
        for (int i = 0; i < m; ++i) {
            int cc = houses[i];
            if (cc == 0) {
                for (int c = 1; c <= n; ++c) {
                    if (i == 0) {
                        dp[i][c-1][1] = cost[i][c-1];
                    } else {
                        for (int k = 1; k <= min(i, target); ++k) {
                            for (int pc = 1; pc <= n; ++pc) {
                                if (dp[i-1][pc-1][k] == numeric_limits<int>::max())
                                    continue;
                                if (pc == c)
                                    dp[i][c-1][k] = min(dp[i][c-1][k], dp[i-1][pc-1][k] + cost[i][c-1]);
                                else if (k < target)
                                    dp[i][c-1][k+1] = min(dp[i][c-1][k+1], dp[i-1][pc-1][k] + cost[i][c-1]);
                            }
                        }
                    }
                }
            } else {
                if (i == 0)
                    dp[i][cc-1][1] = 0;
                else {
                    for (int c = 1; c <= n; ++c) {
                        for (int k = 1; k <= min(i, target); ++k) {
                            if (dp[i-1][c-1][k] == numeric_limits<int>::max())
                                continue;
                            if (c == cc) 
                                dp[i][c-1][k] = min(dp[i][c-1][k], dp[i-1][c-1][k]);
                            else if (k < target)
                                dp[i][cc-1][k+1] = min(dp[i][cc-1][k+1], dp[i-1][c-1][k]);
                        }
                    }
                }
            }
        }
        int res = numeric_limits<int>::max();
        for (int c = 1; c <= n; ++c) {
            res = min(res, dp[m-1][c-1][target]);
        }
        return res != numeric_limits<int>::max() ? res : -1;
    }
};

int main() {
    Solution sol;
    vector<int> houses;
    vector<vector<int>> cost;
    int m, n, target;

    cout << numeric_limits<int>::max() * 2 << endl;
    
    // Output: 9
    houses = {0,0,0,0,0}, cost = {{1,10},{10,1},{10,1},{1,10},{5,1}}, m = 5, n = 2, target = 3;
    //cout << sol.minCost(houses, cost, m, n, target) << endl;
    
    // Output: 11
    houses = {0,2,1,2,0}, cost = {{1,10},{10,1},{10,1},{1,10},{5,1}}, m = 5, n = 2, target = 3;
    //cout << sol.minCost(houses, cost, m, n, target) << endl;
    
    // Output: 5
    houses = {0,0,0,0,0}, cost = {{1,10},{10,1},{1,10},{10,1},{1,10}}, m = 5, n = 2, target = 5;
    //cout << sol.minCost(houses, cost, m, n, target) << endl;
    
    // Output: -1
    houses = {3,1,2,3}, cost = {{1,1,1},{1,1,1},{1,1,1},{1,1,1}}, m = 4, n = 3, target = 3;
    //cout << sol.minCost(houses, cost, m, n, target) << endl;

    // Expected: 4
    houses = {0,0,0,3}, cost = {{2,2,5},{1,5,5},{5,1,2},{5,2,5}}, m = 4, n = 3, target = 3;
    //cout << sol.minCost(houses, cost, m, n, target) << endl;

    // Expected: 1
    houses = {2,3,0}, cost = {{5,2,3},{3,4,1},{1,2,1}}, m = 3, n = 3, target = 3;
    cout << sol.minCost(houses, cost, m, n, target) << endl;
    
    return 0;
}
