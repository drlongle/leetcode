/*
236. Lowest Common Ancestor of a Binary Tree
Total Accepted: 45166 Total Submissions: 156990 Difficulty: Medium

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)."

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int count_nodes(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root) return 0;
    int res = 0;
    res += root == p;
    res += root == q;
    if (res != 2)
    {
        if (root->left)
            res += count_nodes(root->left, p, q);
        if (root->right)
            res += count_nodes(root->right, p, q);
    }

    return res;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return 0;
        if (p == q || p == root || q == root)
            return root;
        TreeNode* pleft = lowestCommonAncestor(root->left, p,q);
        TreeNode* pright = lowestCommonAncestor(root->right, p,q);
        if (pleft && pright) return root;
        if (pleft) return pleft;
        else return pright;
    }

    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p->val == q->val || p->val == root->val || q->val == root->val)
            return root;

        int left_count = count_nodes(root->left, p, q);
        int right_count = count_nodes(root->right, p, q);
        if (left_count > 1) return lowestCommonAncestor(root->left, p,q);
        if (right_count > 1) return lowestCommonAncestor(root->right, p,q);
        if (left_count && right_count) return root;
        if (left_count) return lowestCommonAncestor(root->left, p,q);
        else return lowestCommonAncestor(root->right, p,q);
    }
};

int main()
{
    Solution sol;
    array<TreeNode, 2> nodes = {1,2};
    nodes[0].left = &nodes[1];
    TreeNode* res = sol.lowestCommonAncestor(&nodes[0], &nodes[0], &nodes[1]);
    cout << "Result: " << res-> val << endl;

    return 0;
}

