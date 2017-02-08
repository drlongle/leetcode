/*
145. Binary Tree Postorder Traversal  
Total Accepted: 97683 Total Submissions: 274337 Difficulty: Hard

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> visiting;
        visiting.emplace(root);
        while (visiting.size()) {
            TreeNode* node = visiting.top();
            result.emplace_back(node->val);
            visiting.pop();
            if (node->left)
                visiting.emplace(node->left);

            if (node->right)
                visiting.emplace(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution sol;

    return 0;
}

