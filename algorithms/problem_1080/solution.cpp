/*
1080. Insufficient Nodes in Root to Leaf Paths
Medium

Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.  (A leaf is a node with no children.)

A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.
Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

Example 1:
Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]

Example 2:
Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]

Example 3:
Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]

Note:
The given tree will have between 1 and 5000 nodes.
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool visit(TreeNode* node, int sum, int limit) {
        int count = (node->left != nullptr) + (node->right != nullptr);
        int deleted = 0;
        sum += node->val;
        if (node->left && visit(node->left, sum, limit)) {
            node->left = nullptr;
            ++deleted;
        }
        if (node->right && visit(node->right, sum, limit)) {
            node->right = nullptr;
            ++deleted;
        }

        return (count > 0 && count == deleted) || (count == 0 && sum < limit);
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        auto res = visit(root, 0, limit);
        if (res) return nullptr;
        return root;
    }
};

void test_72() {
    vector<TreeNode> nodes(6, 0);
    nodes[1].val = 1;
    nodes[1].left = &nodes[2];
    nodes[1].right = &nodes[3];
    nodes[2].val = 2;
    nodes[2].left = &nodes[4];
    nodes[3].val = -3;
    nodes[3].left = &nodes[5];
    nodes[4].val = -5;
    nodes[5].val = 4;
    Solution sol;
    sol.sufficientSubset(&nodes[1], -1);
}

int main() {
    test_72();
    return 0;
}
