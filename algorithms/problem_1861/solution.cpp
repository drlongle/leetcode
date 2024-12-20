/*
1861. Rotating the Box
Medium

You are given an m x n matrix of characters box representing a side-view of a
box. Each cell of the box is one of the following: A stone '#' A stationary
obstacle '*' Empty '.' The box is rotated 90 degrees clockwise, causing some of
the stones to fall due to gravity. Each stone falls down until it lands on an
obstacle, another stone, or the bottom of the box. Gravity does not affect the
obstacles' positions, and the inertia from the box's rotation does not affect
the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or
the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

Example 1:
Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]

Example 2:
Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]

Example 3:
Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]

Constraints:
m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    void transform(vector<char> &row) {
        set<int> obstacles;
        int n = row.size();
        for (int i = n - 1; i >= 0; --i) {
            if (row[i] == '*')
                obstacles.insert(i);
        }
        int index = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (row[i] != '#')
                continue;
            if (auto it = obstacles.upper_bound(i); it != obstacles.end()) {
                index = min(index, *it - 1);
            }

            if (index != i) {
                row[i] = '.';
                row[index] = '#';
            }
            --index;
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, ' '));
        for (int i = 0; i < m; ++i) {
            transform(box[i]);
            for (int j = 0; j < n; ++j) {
                res[j][m - i - 1] = box[i][j];
            }
        }

        return res;
    }
};

int main() { return 0; }
