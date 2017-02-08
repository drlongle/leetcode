/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree. 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = static_cast<int>(inorder.size());
        return buildTree(preorder, 0, size-1, inorder, 0, size-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int prebegin, int preend,
        vector<int>& inorder, int inbegin, int inend) {
        if (prebegin > preend) return NULL;
        int val = preorder[prebegin];
        vector<int>::iterator it;
        it = find(inorder.begin() + inbegin, inorder.begin() + inend+1, val);
        int leftsize = it - inorder.begin() - inbegin;
        TreeNode *root = new TreeNode(val);
        root->left = buildTree(preorder, prebegin+1, prebegin+leftsize,
            inorder, inbegin, inbegin + leftsize-1);
        root->right = buildTree(preorder, prebegin + leftsize+1, preend,
            inorder, inbegin + leftsize+1, inend);
        return root;
    }
};

int main()
{
    return 0;
}
