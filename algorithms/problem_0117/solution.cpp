/*
117. Populating Next Right Pointers in Each Node II

Given a binary tree

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Note:
    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

#include <algorithm>
#include <array>
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

struct TreeLinkNode {
    TreeLinkNode(int v) : left(0), right(0), next(0), val(v) { }
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    int val;
};

class Solution {
public:
    void connect(TreeLinkNode *root);
};

void Solution::connect(TreeLinkNode *root)
{
    if (!root) return;

    array<vector<TreeLinkNode*>, 2> visits;
    int index = 0;
    visits[0].emplace_back(root);
    while (visits[index].size())
    {
        int nsize = visits[index].size();
        for (int i = 0; i < nsize; ++i)
        {
            TreeLinkNode *node = visits[index][i];
            if (i < nsize-1)
                node->next = visits[index][i+1];
            if (node->left)
                visits[1-index].emplace_back(node->left);
            if (node->right)
                visits[1-index].emplace_back(node->right);
        }
        visits[index].clear();
        index = 1-index;
    }
}

int main()
{
    Solution sol;
    array<TreeLinkNode, 7> nodes = {0,1,2,3,4,5,6};
    int nsize = nodes.size();
    for (int i = 0; i < (nsize>>1); ++i)
    {
        nodes[i].left = &nodes[(i << 1) + 1];
        nodes[i].right = &nodes[(i << 1) + 2 ];
    }
    sol.connect(&nodes[0]);
  
    return 0;
}

