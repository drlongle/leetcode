/*
1022. Sum of Root To Leaf Binary Numbers
Easy

Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting
with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent
01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

Example 1:
Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Note:
The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum;

    void visit(TreeNode* node, int running) {
        if (!node)
            return;
        running = (running << 1) + node->val;
        if (!node->left && !node->right) {
            sum += running;
            return;
        }
        visit(node->left, running);
        visit(node->right, running);
    }

    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        visit(root, 0);
        return sum;
    }
};

int main() {
    Solution sol;

    return 0;
}
