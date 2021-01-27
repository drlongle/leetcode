/*
1102. Path With Maximum Minimum Value
Medium

Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting
at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path
8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one
of the 4 cardinal directions (north, east, west, south).

Example 1:
Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation:
The path with the maximum score is highlighted in yellow.

Example 2:
Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2

Example 3:
Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3

Note:
1 <= R, C <= 100
0 <= A[i][j] <= 10^9
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
    int maximumMinimumPath(vector<vector<int>>& grid) {
        using T = tuple<int, int, int>;
        auto lambda = [] (const T& a, const T& b) {
            return get<2>(a) < get<2>(b);
        };
        priority_queue<T, vector<T>, decltype(lambda)> pq(lambda);
        vector<vector<int>> offsets{{-1,0}, {1,0}, {0,1}, {0,-1}};

        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.emplace(0, 0, grid[0][0]);
        visited[0][0] = true;
        while (!pq.empty()) {
            auto tup = pq.top();
            int i = get<0>(tup), j = get<1>(tup), val = get<2>(tup);
            pq.pop();
            if ((i == m-1 && j == n-1) || val == 0)
                return val;
            for (auto& offset: offsets) {
                int ni = i + offset[0], nj = j + offset[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    pq.emplace(ni, nj, min(val, grid[ni][nj]));
                    visited[ni][nj] = true;
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 4
    grid = {{5,4,5},{1,2,6},{7,4,6}};
    cout << sol.maximumMinimumPath(grid) << endl;

    // Output: 2
    grid = {{2,2,1,2,2,2},{1,2,2,2,1,2}};
    cout << sol.maximumMinimumPath(grid) << endl;

    // Output: 3
    grid = {{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
    cout << sol.maximumMinimumPath(grid) << endl;

    // Output: 0
    grid = {{0,1,0,0,1},{1,1,0,0,0},{1,0,1,1,1},{1,0,1,0,1},{1,0,1,0,1}};
    cout << sol.maximumMinimumPath(grid) << endl;

    return 0;
}
