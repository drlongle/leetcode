/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, int inbegin, int inend,
        vector<int>& postorder, int postbegin, int postend) {
        if (postbegin > postend) return NULL;
        int val = postorder[postend];
        vector<int>::iterator it;
        it = find(inorder.begin() + inbegin, inorder.begin() + inend+1, val);
        int leftsize = it - inorder.begin() - inbegin;
        TreeNode *root = new TreeNode(val);
        root->left = buildTree(inorder, inbegin, inbegin + leftsize -1,
            postorder, postbegin, postbegin + leftsize-1);
        root->right = buildTree(inorder, inbegin + leftsize+1, inend,
            postorder, postbegin+leftsize, postend-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = static_cast<int>(inorder.size());
        return buildTree(inorder, 0, size-1, postorder, 0, size-1);
    }
};

int main()
{
    return 0;
}
