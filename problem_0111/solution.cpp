/*
111. Minimum Depth of Binary Tree
Total Accepted: 111167 Total Submissions: 359448 Difficulty: Easy

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* A);
};

int Solution::minDepth(TreeNode* root)
{
    if (!root) return 0;
    if (!root->left) return 1+minDepth(root->right);
    if (!root->right) return 1+minDepth(root->left);
    return 1 + min(minDepth(root->left),minDepth(root->right));
}

int main()
{
    Solution sol;

    return 0;
}

