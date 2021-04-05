/*
971. Flip Binary Tree To Match Preorder Traversal
Medium

You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n.
You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.

Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping
node 1 will have the following effect:


Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.

Return a list of the values of all flipped nodes. You may return the answer in any order.
If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage,
return the list [-1].

Example 1:
Input: root = [1,2], voyage = [2,1]
Output: [-1]
Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.

Example 2:
Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.

Example 3:
Input: root = [1,2,3], voyage = [1,2,3]
Output: []
Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.

Constraints:
The number of nodes in the tree is n.
n == voyage.length
1 <= n <= 100
1 <= Node.val, voyage[i] <= n
All the values in the tree are unique.
All the values in voyage are unique.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    vector<int> res;
    unordered_map<int, int> lookup;

    bool DFS(TreeNode* root, vector<int>& voyage, int start, int end) {
        if (!root && start > end)
            return true;
        if (!root || start > end)
            return false;
        if (root->val != voyage[start])
            return false;
        if (root->left && root->left->val != voyage[start+1]) {
            res.push_back(root->val);
            swap(root->left, root->right);
        }

        if (root->right) {
            auto it = lookup.find(root->right->val);
            if (it == lookup.end())
                return false;
            int start_right = lookup[root->right->val];
            return DFS(root->left, voyage, start+1, start_right-1) && DFS(root->right, voyage, start_right, end);
        } else {
            return DFS(root->left, voyage, start+1, end);
        }
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int n = voyage.size();
        for (int i = 0; i < n; ++i) {
            lookup[voyage[i]] = i;
        }
        if (!DFS(root, voyage, 0, n-1)) {
            return {-1};
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
