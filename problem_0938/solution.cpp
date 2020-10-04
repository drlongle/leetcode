/*
938. Range Sum of BST
Easy

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

Example 1:
Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

Note:
The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
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
};

class Solution {
public:
    void visit(TreeNode* node, int L, int R) {
        if (!node)
            return;
        if (node->val >= L && node->val <= R)
            sum += node->val;
        if (node->val > R)
            visit(node->right, L, R);
        if (node->val < L)
            visit(node->left, L, R);
    }

    int sum;
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        visit(root, L, R);
        return sum;
    }
};

int main() {
    Solution sol;

    return 0;
}
