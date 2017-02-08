/*
107. Binary Tree Level Order Traversal II
Total Accepted: 84445 Total Submissions: 244770 Difficulty: Easy

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

#include <algorithm>
#include <array>
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
#include <unordered_set>
#include <unordered_map>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        array<queue<TreeNode*>,2> visits;
        if (!root) return res;
        int queue_index = 0, result_index = 0;

        visits[0].emplace(root);
        while (visits[0].size() || visits[1].size())
        {
            res.emplace_back(vector<int>());
            while (visits[queue_index].size())
            {
                TreeNode* node = visits[queue_index].front();
                visits[queue_index].pop();
                res[result_index].emplace_back(node->val);
                if (node->left) visits[1-queue_index].emplace(node->left);
                if (node->right) visits[1-queue_index].emplace(node->right);
            }
            queue_index = 1 - queue_index;
            ++result_index;
        }
        reverse(res.begin(),res.end());

        return res;
    }
};

int main()
{
    Solution sol;

    return 0;
}

