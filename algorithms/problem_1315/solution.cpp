/*
1315. Sum of Nodes with Even-Valued Grandparent
Medium

Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

Example 1:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18

Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents. 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while (q.size()) {
            auto& node = q.front();
            bool even = (node->val % 2 == 0);
            if (node->left) {
                q.emplace(node->left);
                if (even) {
                    res += (node->left->left) ? node->left->left->val : 0;
                    res += (node->left->right) ? node->left->right->val : 0;
                }
            }
            if (node->right) {
                q.emplace(node->right);
                if (even) {
                    res += (node->right->left) ? node->right->left->val : 0;
                    res += (node->right->right) ? node->right->right->val : 0;
                }
            }

            q.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
