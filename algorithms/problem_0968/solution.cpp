/*
968. Binary Tree Cameras
Hard

Given a binary tree, we install cameras on the nodes of the tree.
Each camera at a node can monitor its parent, itself, and its immediate children.
Calculate the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows
one of the valid configurations of camera placement.

Note:
The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    map<pair <TreeNode *, int>, int> cache;
    /*
     * monitored has three values:
     * 1: parent has a camera (parent node passes coverage to the current node)
     * 0: parent's parent has a camera
     * -1: parent and parent's parent do not have a camera. In this case,
     *     one of the children (left or right) need to have a camera
     */
    int visit(TreeNode *node, int monitored) {
        if (!node) return 0;
        auto key = make_pair(node, monitored);
        auto it = cache.find(key);
        if (it != cache.end())
            return it->second;
        int res = 1 + visit(node->left, 1) + visit(node->right, 1);
        if (monitored > 0)
            res = min(res, visit (node->left,0) + visit (node->right, 0));
        else if (!monitored) {
            if (node->left) {
                res = min(res, visit(node->left, -1) + visit(node->right, 0));
            }
            if (node->right) {
                res = min(res, visit(node->left, 0) + visit(node->right, -1));
            }
        }

        return cache[key] =  res;
    }

    int minCameraCover(TreeNode* root) {
        return  visit (root, 0);
    }
};

int main() {
    Solution sol;

    return 0;
}
