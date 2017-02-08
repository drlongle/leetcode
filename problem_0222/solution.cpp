/*
222. Count Complete Tree Nodes
Total Accepted: 34617 Total Submissions: 135994 Difficulty: Medium

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.
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

int get_height(TreeNode* root)
{
    int res;
    while(root)
    {
        ++res;
        root = root->left;
    }
    return res;
}

TreeNode* find_node(TreeNode* root, int height, int step, int index)
{
    if (height == step)
        return root;
    if (index >= 1 << (height-step-1))
    {
        if (root->right)
            return find_node(root->right, height, step+1,
                index - (1 << (height-step-1)));
        else
            return NULL;
    }
    else
    {
        if (root->left)
            return find_node(root->left, height, step+1, index);
        else
            return 0;
    }
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int height = get_height(root);
        int begin = 0;
        int end = (1 << height) - 1;
        while (begin < end)
        {
            int mid = begin + ((end-begin) >> 1);
            if (find_node(root, height, 0, mid))
                begin = mid+1;
            else
                end = mid-1;
        }
        if (find_node(root, height, 0, begin) == 0)
            --begin;

        return (1 << height)  + begin;
    }
};

int main()
{
    Solution sol;

    return 0;
}

