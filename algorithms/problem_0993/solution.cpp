/*
993. Cousins in Binary Tree
Difficulty: Easy

In a binary tree, the root node is at depth 0, and children of each depth k
node are at depth k+1. Two nodes of a binary tree are cousins if they have the
same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values
x and y of two different nodes in the tree. Return true if and only if the
nodes corresponding to the values x and y are cousins.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void explore(TreeNode* parent, int depth, TreeNode* node) {
        lookup[node->val] = make_pair(depth, parent);
        if (node->left)
            explore(node, depth+1, node->left);
        if (node->right)
            explore(node, depth+1, node->right);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        explore(nullptr, 0, root);
        return lookup[x].first == lookup[y].first && lookup[x].second != lookup[y].second;
    }
    
    map<int, pair<int, TreeNode*>> lookup;
};

int main(int argc, char** argv) {
    Solution sol;
    return 0;
}
