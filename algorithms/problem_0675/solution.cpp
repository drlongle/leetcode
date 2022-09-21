/*
675. Cut Off Trees for Golf Event
Hard

You are asked to cut off all the trees in a forest for a golf event. The forest
is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through,
and this number is the tree's height. In one step, you can walk in any of the
four directions: north, east, south, and west. If you are standing in a cell
with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a
tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut
off all the trees. If you cannot cut off all the trees, return -1.

Note: The input is generated such that no two trees have the same height, and
there is at least one tree needs to be cut off.

Example 1:
Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from
shortest to tallest in 6 steps.

Example 2:
Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is
blocked.

Example 3:
Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.

Constraints:
m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109
Heights of all trees are distinct.
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int visited[50][50];
    vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int cutOffTree(vector<vector<int>> &forest) {
        vector<pair<int, int>> dq;
        int m = forest.size(), n = forest[0].size(), res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (forest[i][j] && forest[i][j] != 1)
                    dq.emplace_back(i, j);

        auto lambda = [&forest](auto &a, auto &b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        };
        sort(begin(dq), end(dq), lambda);
        pair<int, int> curr{0, 0};
        size_t index = 0, sz = dq.size();
        while (index < sz) {
            memset(visited, 0, sizeof(int) * 50 * 50);
            queue<pair<int, int>> q;
            q.emplace(curr.first, curr.second);
            visited[curr.first][curr.second] = 1;

            auto &cell = dq[index];
            bool found = false;
            while (!q.empty()) {
                auto c = q.front();
                q.pop();
                int x = c.first, y = c.second, dist = visited[x][y];
                if (x == cell.first && y == cell.second) {
                    res += dist - 1;
                    found = true;
                    break;
                }
                for (auto &offset : offsets) {
                    int nx = x + offset[0], ny = y + offset[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        forest[nx][ny] > 0 && !visited[nx][ny]) {
                        q.emplace(nx, ny);
                        visited[nx][ny] = dist + 1;
                    }
                }
            }
            curr = cell;
            if (!found)
                return -1;
            ++index;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> forest;

    // Output: 6
    forest = {{1, 2, 3}, {0, 0, 4}, {7, 6, 5}};
    cout << sol.cutOffTree(forest) << endl;

    // Output: 10
    forest = {{4, 2, 3}, {0, 0, 1}, {7, 6, 5}};
    cout << sol.cutOffTree(forest) << endl;

    // Output: 57
    forest = {{54581641, 64080174, 24346381, 69107959},
              {86374198, 61363882, 68783324, 79706116},
              {668150, 92178815, 89819108, 94701471},
              {83920491, 22724204, 46281641, 47531096},
              {89078499, 18904913, 25462145, 60813308}};
    cout << sol.cutOffTree(forest) << endl;

    return 0;
}
