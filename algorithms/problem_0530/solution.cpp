/*
530. Minimum Absolute Difference in BST
Easy

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
#include <memory>
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
     pair<int, int> visit(TreeNode* node) {
         pair<int, int> res{node->val, node->val};
         if (node->left) {
             auto lr = visit(node->left);
             mindiff = min(mindiff, node->val - lr.second);
             res.first = lr.first;
         }
         if (node->right) {
             auto rr = visit(node->right);
             mindiff = min(mindiff, rr.first - node->val);
             res.second = rr.second;
         }
         return res;
     }
     int mindiff;
     int getMinimumDifference(TreeNode* root) {
         mindiff = numeric_limits<int>::max();
         visit(root);
         return mindiff;
     }
 };

int main() {
    Solution sol;
    return 0;
}
