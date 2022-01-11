/*
113. Path Sum II
Total Accepted: 83228 Total Submissions: 291368 Difficulty: Medium

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]
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


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) ;
};

void find_path_sum(TreeNode* root, int sum, vector<int>&path,
    vector<vector<int>>& res)
{
    if (!root) return;
    int diff = sum - root->val;
    path.emplace_back(root->val);
    if (root->left || root->right)
    {
        find_path_sum(root->left, diff, path, res);
        find_path_sum(root->right, diff, path, res);
    }
    else if (!diff)
        res.emplace_back(path);
    path.pop_back();
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> res;
    vector<int> path;

    find_path_sum(root, sum, path, res);

    return res;
}

int main()
{
    Solution sol;

    return 0;
}

