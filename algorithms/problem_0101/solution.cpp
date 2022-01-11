/*
101. Symmetric Tree
Total Accepted: 111807 Total Submissions: 325762 Difficulty: Easy

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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

class Solution {
public:
    bool isSymmetric(TreeNode* root); 
};

bool is_symmetric_recursive(TreeNode* n1, TreeNode* n2)
{
    if (!n1 && !n2) return true;
    if (!n1 || !n2) return false;
    if (n1->val != n2->val) return false;
    return is_symmetric_recursive(n1->left,n2->right)
        && is_symmetric_recursive(n1->right,n2->left);
}

bool Solution::isSymmetric(TreeNode* root)
{
    if (!root) return true;
    bool recursive = false;
    if (recursive)
        return is_symmetric_recursive(root->left,root->right);
    queue<pair<TreeNode*,TreeNode*>> visits;
    visits.emplace(root->left,root->right);
    while (visits.size())
    {
        pair<TreeNode*,TreeNode*> nodes = visits.front();
        visits.pop();
        if (!nodes.first && !nodes.second) continue;
        if (!nodes.first || !nodes.second) return false;
        if (nodes.first->val != nodes.second->val) return false;
        visits.emplace(nodes.first->left,nodes.second->right);
        visits.emplace(nodes.first->right,nodes.second->left);
    }

    return true;
}

int main()
{
    Solution sol;

    return 0;
}

