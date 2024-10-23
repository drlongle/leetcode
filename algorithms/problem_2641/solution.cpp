/*
2641. Cousins in Binary Tree II
Medium

Given the root of a binary tree, replace the value of each node in the tree with
the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with
different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root
node to it.

Example 1:
Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree
after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.

Example 2:
Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree
after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.

Constraints:
The number of nodes in the tree is in the range [1, 10^5].
1 <= Node.val <= 10^4
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
    vector<int> sums;

    void buildSums(TreeNode *node, size_t level) {
        if (!node)
            return;
        if (level + 1 > sums.size())
            sums.resize(level + 1);
        sums[level] += node->val;
        buildSums(node->left, level + 1);
        buildSums(node->right, level + 1);
    }

    void setSums(TreeNode *node, size_t level) {
        if (!node)
            return;
        int s = (node->left ? node->left->val : 0) +
                (node->right ? node->right->val : 0);
        if (node->left) {
            node->left->val = sums[level + 1] - s;
            setSums(node->left, level + 1);
        }
        if (node->right) {
            node->right->val = sums[level + 1] - s;
            setSums(node->right, level + 1);
        }
    }

    TreeNode *replaceValueInTree(TreeNode *root) {
        sums.clear();
        buildSums(root, 0);
        setSums(root, 0);
        if (root)
            root->val = 0;
        return root;
    }
};

int main() { return 0; }
