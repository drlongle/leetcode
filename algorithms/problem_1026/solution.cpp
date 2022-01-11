/*
1026. Maximum Difference Between Node and Ancestor
Medium

Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)
Example 1:
Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Note:
The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.
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
     pair<int, int> visit(TreeNode* root) {
         int minval = root->val, maxval = root->val;
         if (root->left) {
             auto lr = visit(root->left);
             minval = min(minval, lr.first);
             maxval = max(maxval, lr.second);
         }
         if (root->right) {
             auto rr = visit(root->right);
             minval = min(minval, rr.first);
             maxval = max(maxval, rr.second);
         }
         res = max(max(abs(root->val - minval), abs(root->val - maxval)), res);
         return {minval, maxval};
     }

     int maxAncestorDiff(TreeNode* root) {
         res = numeric_limits<int>::min();
         visit(root);
         return res;
     }
     int res;
 };

int main() {
    Solution sol;
    return 0;
}
