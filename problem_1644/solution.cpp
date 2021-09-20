/*
1644. Lowest Common Ancestor of a Binary Tree II
Medium

Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q.
If either node p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in
a binary tree T is the lowest node that has both p and q as descendants (where we allow a node to be
a descendant of itself)". A descendant of a node x is a node y that is on the path from node x to some leaf node.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.

Example 3:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
Output: null
Explanation: Node 10 does not exist in the tree, so return null.

Constraints:
The number of nodes in the tree is in the range [1, 104].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q

Follow up: Can you find the LCA traversing the tree, without checking nodes existence?
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

    TreeNode* res = nullptr;
    unordered_map<TreeNode*, int> cached;

    int countChildren(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return 0;
        auto it = cached.find(root);
        if (it != cached.end())
            return it->second;
        return cached[root] = (root == p) + (root == q) + countChildren(root->left, p, q) + countChildren(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        int lc = countChildren(root->left, p, q);
        int rc = countChildren(root->right, p, q);
        if (lc == 1 &&  rc == 1)
            return root;
        if (lc == 2)
            return lowestCommonAncestor(root->left, p, q);
        if (rc == 2)
            return lowestCommonAncestor(root->right, p,q);
        if (lc + rc + (root == p) + (root == q) == 2)
            return root;
        return nullptr;
    }
};

int main() {
    Solution sol;

    return 0;
}
