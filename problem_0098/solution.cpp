/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root, int& min_val, int& max_val) {
        min_val = max_val = root->val;
        if (root->left) {
            int left_min, left_max;
            if (!isValidBST(root->left, left_min, left_max))
                return false;
            if (left_max >= root->val)
                return false;
            if (left_min < min_val)
                min_val = left_min;
        }

        if (root->right) {
            int right_min, right_max;
            if (!isValidBST(root->right, right_min, right_max))
                return false;
            if (right_min <= root->val)
                return false;
            if (right_max > max_val) max_val = right_max;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int min_val, max_val;
        return isValidBST(root, min_val, max_val);
    }
};

int main()
{
    Solution sol;
    cout << boolalpha << sol.isValidBST(0) << endl;
    return 0;
}
