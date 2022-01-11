/*
305. Number of Islands II
Hard

You are given an empty 2D binary grid of size m x n. The grid represents a map where 0's represent water
and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. You are given an array
positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.

Example 2:
Input: m = 1, n = 1, positions = [[0,0]]
Output: [1]

Constraints:
1 <= m, n, positions.length <= 10^4
1 <= m * n <= 10^4
positions[i].length == 2
0 <= ri < m
0 <= ci < n

Follow up: Could you solve it in time complexity O(k log(mn)), where k == positions.length?
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

class Solution {
public:
    int mapping(int row, int col) {
        return row* 10000 + col;
    }

    unordered_map<int, int> roots;

    int get_root(int n) {
        while (true) {
            int r = roots[n];
            if (n != r) {
                n = r;
            } else
                break;
        }
        return n;
    }

    void join_root(int n, int root) {
        while (true) {
            int next = roots[n];
            if (next == root)
                break;
            roots[n] = root;
            n = next;
        }
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> offsets {{0,1},{0,-1},{1,0},{-1,0}}, grid(m, vector<int>(n, 0));
        vector<int> res;
        int islands = 0;

        for (auto& pos: positions) {
            int x = pos[0], y = pos[1], p = mapping (x, y);
            if (!roots.emplace(p, p).second) {
                res.push_back(islands);
                continue;
            }
            ++islands;
            grid[x][y] = 1;
            for (auto & offset: offsets) {
                int nx = x + offset[0], ny = y + offset[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]) {
                    int rp = get_root(p);
                    int nn = mapping(nx, ny), rn = get_root(nn);
                    if (rn == rp) {
                        continue;
                    }
                    --islands;

                    if (rn < rp)
                        join_root(p, nn);
                    else
                        join_root(nn, rp);
                }
            }

            res.push_back(islands);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
