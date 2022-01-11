/*
513. Find Bottom Left Tree Value
Medium

Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1

Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> curr{root};
        int res;
        while (curr.size()) {
            res = curr[0]->val;
            vector<TreeNode*> next;
            for (auto& n: curr) {
                if (n->left)
                    next.emplace_back(n->left);
                if (n->right)
                    next.emplace_back(n->right);
            }
            curr = move(next);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
