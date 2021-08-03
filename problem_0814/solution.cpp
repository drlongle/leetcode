/*
814. Binary Tree Pruning
Medium

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing
a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

Example 1:
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Constraints:
The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool visit(TreeNode*& node) {
        if (!node)
            return false;
        bool res = node->val;
        res |= visit(node->left);
        res |= visit(node->right);
        if (!res)
            node = nullptr;
        return res;
    }

    TreeNode* pruneTree(TreeNode* root) {
        visit(root);
        return root;
    }
};

int main() {
    return 0;
}
