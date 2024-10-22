/*
2583. Kth Largest Sum in a Binary Tree
Medium

You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the
same level.

Return the kth largest level sum in the tree (not necessarily distinct). If
there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from
the root.

Example 1:
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:
Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.

Constraints:
    The number of nodes in the tree is n.
    2 <= n <= 10^5
    1 <= Node.val <= 10^6
    1 <= k <= n
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
    vector<long long> sums;

    void visit(TreeNode *node, size_t level) {
        if (!node)
            return;
        if (sums.size() < level + 1)
            sums.resize(level + 1);
        sums[level] += node->val;
        visit(node->left, level + 1);
        visit(node->right, level + 1);
    }

    long long kthLargestLevelSum(TreeNode *root, int k) {
        visit(root, 0);
        ranges::sort(sums, [](auto a, auto b) { return a > b; });
        if (k > static_cast<int>(sums.size()))
            return -1;

        return sums[k - 1];
    }
};

int main() { return 0; }
