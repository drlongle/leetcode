/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> visiting;
        TreeNode* node = root;
        while(node || visiting.size()) {
            if (node) {
                if (node->left) {
                    visiting.push(node);
                    node = node->left;
                } else {
                    result.push_back(node->val);
                    node = node->right;
                }
            }
            else
            {
                node = visiting.top();
                visiting.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
