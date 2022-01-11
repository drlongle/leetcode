/*
623. Add One Row to Tree
Medium

Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with
value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1,
create two tree nodes with value v as N's left subtree root and right subtree root. And N's original
left subtree should be the left subtree of the new left subtree root, its original right subtree
should be the right subtree of the new right subtree root. If depth d is 1 that means there is no
depth d-1 at all, then create a tree node with value v as the new root of the whole original tree,
and the original tree is the new root's left subtree.

Example 1:
Input:
A binary tree as following:
       4
     /   \
    2     6
   / \   /
  3   1 5

v = 1
d = 2

Output:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5

Example 2:
Input:
A binary tree as following:
      4
     /
    2
   / \
  3   1

v = 1
d = 3

Output:
      4
     /
    2
   / \
  1   1
 /     \
3       1

Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.

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

    void DFS(TreeNode* root, int v, int d, int level) {
        if (level + 1 == d) {
            root->left = new TreeNode(v, root->left, nullptr);
            root->right = new TreeNode(v, nullptr, root->right);
        } else {
            if (root->left)
                DFS(root->left, v, d, level + 1);
            if (root->right)
                DFS(root->right, v, d, level+1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }

        DFS(root, v, d, 1);

        return root;
    }
};

int main() {
    Solution sol;

    return 0;
}
