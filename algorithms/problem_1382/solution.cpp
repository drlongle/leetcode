/*
1382. Balance a Binary Search Tree
Medium

Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.

Constraints:
The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.
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
    vector<int> vals;

    void serialize(TreeNode* node) {
        if (!node)
            return;
        serialize(node->left);
        vals.emplace_back(node->val);
        serialize(node->right);
    }

    TreeNode* makeBST(int begin, int end) {
        if (begin > end)
            return nullptr;
        int mid = (begin + end) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = makeBST(begin, mid-1);
        node->right = makeBST(mid+1, end);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        serialize(root);
        return makeBST(0, vals.size()-1);
    }
};

int main() {
    Solution sol;
    return 0;
}
