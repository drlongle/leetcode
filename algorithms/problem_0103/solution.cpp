/*
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        array<vector<TreeNode*>, 2> visiting;
        if (!root) return result;
        visiting[0].push_back(root);
        int index = 0;
        while(visiting[0].size() || visiting[1].size())
        {
            vector<int> row;
            int size = static_cast<int>(visiting[index].size());
            for (int i = 0; i < size; ++i) {
                TreeNode* node = visiting[index][i];
                if(index == 0)
                    row.push_back(node->val);
                if (node->left)
                    visiting[1-index].emplace_back(node->left);
                if (node->right)
                    visiting[1-index].emplace_back(node->right);
            }

            if (index != 0) {
                for (int i = size-1; i >= 0; --i) {
                    TreeNode* node = visiting[index][i];
                    row.push_back(node->val);
                }
            }
            visiting[index].clear();
            index = 1-index;
            result.emplace_back(row);
        }

        return result;
    }
};

int main()
{
    return 0;
}
