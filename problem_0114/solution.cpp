/*
114. Flatten Binary Tree to Linked List

 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *tail;
        flatten(root, &tail);
    }

    void flatten(TreeNode* root, TreeNode**tail) {
        if (!root) {
            *tail = NULL;
            return;
        }

        *tail = root;
        if (root->left) flatten(root->left, tail);
        (*tail)->right = root->right;
        if (root->right) flatten(root->right, tail);
        if (root->left) root->right = root->left;
        root->left = NULL;
    }
};

int main()
{
    Solution sol;

    return 0;
}
