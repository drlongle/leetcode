/*
333. Largest BST Subtree
Medium

Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST),
where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.

Follow up: Can you figure out ways to solve it with O(n) time complexity?
Example 1:
Input: root = [10,5,15,1,8,null,7]
Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree's size, which is 3.

Example 2:
Input: root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 104].
-10^4 <= Node.val <= 10^4
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
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
    tuple<int, long, long> getBST(TreeNode* node) {
        if (!node)
            return make_tuple(0, 0, 0);
        res = max(1, res);
        long val = node->val, minv = val, maxv = val;
        int sz = 1;
        if (node->left) {
            auto l = getBST(node->left);
            sz = get<0>(l) < 0 ? -1 : sz + get<0>(l);
            minv = min(minv, get<1>(l));
            maxv = max(maxv, get<2>(l));
            if (val <= get<2>(l))
                sz = -1;
        }
        if (node->right) {
            auto l = getBST(node->right);
            if (sz > 0)
                sz = get<0>(l) < 0 ? -1 : sz + get<0>(l);
            minv = min(minv, get<1>(l));
            maxv = max(maxv, get<2>(l));
            if (val >= get<1>(l))
                sz = -1;
        }
        if (sz >= 0)
            res = max(res, sz);
        return make_tuple(sz, minv, maxv);
    }
    int res = 0;
    int largestBSTSubtree(TreeNode* root) {
        if (root)
            getBST(root);

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
