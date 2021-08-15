/*
776. Split BST
Medium

Given the root of a binary search tree (BST) and an integer target, split the tree into two subtrees where
one subtree has nodes that are all smaller or equal to the target value, while the other subtree has all nodes
that are greater than the target value. It Is not necessarily the case that the tree contains a node with
the value target.

Additionally, most of the structure of the original tree should remain. Formally, for any child c with
parent p in the original tree, if they are both in the same subtree after the split, then node c should
still have the parent p.

Return an array of the two roots of the two subtrees.

Example 1:
Input: root = [4,2,6,1,3,5,7], target = 2
Output: [[2,1],[4,3,6,null,null,5,7]]

Example 2:
Input: root = [1], target = 1
Output: [[1],[]]

Constraints:
The number of nodes in the tree is in the range [1, 50].
0 <= Node.val, target <= 1000
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

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:

    vector<TreeNode*> res;

    void visit(TreeNode* node,  int val) {
        if (!node) {
            return;
        }
        auto left = node->left;
        auto right = node->right;
        node->left = node->right = nullptr;
        if (node->val <= val) {
            if (!res[0])
                res[0] = node;
            else
                insert(res[0], node);
        } else {
            if (!res[1])
                res[1] = node;
            else
                insert(res[1], node);
        }
        visit(left, val);
        visit(right, val);
    }

    void insert(TreeNode* root, TreeNode* node){
        if (node->val <= root->val) {
            if (root->left)
                insert(root->left, node);
            else
                root->left = node;
        } else {
            if (root->right)
                insert(root->right, node);
            else
                root->right = node;
        }
    }

    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        res.resize(2, nullptr);
        visit(root, V);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
