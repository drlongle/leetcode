/*
998. Maximum Binary Tree II
Difficulty: Medium

We are given the root node of a maximum tree: a tree where every
node has a value greater than any other value in its subtree.

Just as in the previous problem, the given tree was constructed from
a list A (root = Construct(A)) recursively with the following Construct(A) routine:

If A is empty, return null.
Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
Return root.
Note that we were not given A directly, only a root node root = Construct(A).

Suppose B is a copy of A with the value val appended to it. It is guaranteed
that B has unique values. Return Construct(B).
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void insertToTree(TreeNode* parent, TreeNode* curr, int val) {
        if (curr == nullptr || curr->val < val) {
            TreeNode* node = new TreeNode(val);
            node->left = curr;
            if (parent)
                parent->right = node;
        } else {
            insertToTree(curr, curr->right, val);
        }
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr || root->val < val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        insertToTree(nullptr, root, val);

        return root;
    }
};

int main() {
    Solution sol;
    return 0;
}
