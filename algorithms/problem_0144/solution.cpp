/*
144. Binary Tree Preorder Traversal  
Total Accepted: 121141 Total Submissions: 302708 Difficulty: Medium

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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

#define ll long long int
#define ull unsigned long long int

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> visiting;
        visiting.emplace(root);
        while (visiting.size()) {
            TreeNode* node = visiting.top();
            result.emplace_back(node->val);
            visiting.pop();
            if (node->right)
                visiting.emplace(node->right);
            if (node->left)
                visiting.emplace(node->left);
        }
        
        return result;
    }
};

int main()
{
    Solution sol;

    return 0;
}

