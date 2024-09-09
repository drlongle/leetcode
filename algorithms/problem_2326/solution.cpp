/*
2326. Spiral Matrix IV
Medium

You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented
in spiral order (clockwise), starting from the top-left of the matrix. If there
are remaining empty spaces, fill them with -1.

Return the generated matrix.

Example 1:
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Example 2:
Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to
right in the matrix. The last space in the matrix is set to -1.

Constraints:
1 <= m, n <= 10^5
1 <= m * n <= 10^5
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int row = 0, col = 0;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_index = 0;
        int left_limit = 0, right_limit = n - 1;
        int top_limit = 0, bottom_limit = m - 1;

        while (head) {
            // cout << " index: " << dir_index << " row: " << row << " col: " <<
            // col << " val: " << head->val << endl;
            res[row][col] = head->val;
            head = head->next;
            if (dir_index == 0 && col == right_limit) {
                ++top_limit;
                dir_index = (dir_index + 1) % 4;
            } else if (dir_index == 1 && row == bottom_limit) {
                --right_limit;
                dir_index = (dir_index + 1) % 4;
            } else if (dir_index == 2 && col == left_limit) {
                --bottom_limit;
                dir_index = (dir_index + 1) % 4;
            } else if (dir_index == 3 && row == top_limit) {
                ++left_limit;
                dir_index = (dir_index + 1) % 4;
            }
            row = row + dirs[dir_index][0];
            col = col + dirs[dir_index][1];
        }

        return res;
    }
};

int main() { return 0; }
