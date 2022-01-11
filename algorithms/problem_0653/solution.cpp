/*
653. Two Sum IV - Input is a BST
Easy

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
Output: True

Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
Output: False
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
    unordered_map<int, int> nums;
    void visit(TreeNode* root) {
        if (!root)
            return;
        ++nums[root->val];
        visit(root->left);
        visit(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        visit(root);
        for (auto [n, v]: nums) {
            int index = k-n;
            auto it = nums.find(k-n);
            if (it == nums.end())
                continue;
            int c = it->second;
            if ((2*n != k && c > 0) || (2*n == k && c > 1)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}
