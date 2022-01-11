/*
124. Binary Tree Maximum Path Sum
Total Accepted: 58563 Total Submissions: 257039 Difficulty: Hard

Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        pair<int,int> result = maxSum(root);
        return max(result.first, result.second); 
    }

    pair<int, int> maxSum(TreeNode* root) {
        pair<int,int> result(root->val, root->val);
        if (!root->left && !root->right) return result;
        pair<int,int> left, right;
        if (root->left) {
            left = maxSum(root->left);
            if (max(left.first,left.second) > result.first)
                result.first = max(left.first, left.second);
        }
        if (root->right) {
            right = maxSum(root->right);
            if (max(right.first,right.second) > result.first)
                result.first = max(right.first, right.second);
        }
        int sum = (root->left ? left.second : 0) +
            root->val + (root->right ? right.second : 0);
        if (sum > result.first) result.first = sum;
        if (root->left && root->right)
            result.second = max(max(left.second , right.second) +
                root->val, result.second);
        else if (root->left && left.second > 0)
            result.second += left.second;
        else if (root->right && right.second > 0)
            result.second += right.second;
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}
