/*
958. Check Completeness of a Binary Tree
Medium

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible. It can have between 1 and 2^h
nodes inclusive at the last level h.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}),
and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.

Constraints:
The number of nodes in the tree is in the range [1, 100].
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
    pair<bool, bool> check(TreeNode* root, int height) {
        if (!root)
            return {height == 0, false};
        if (height == 1 && !root->left && !root->right)
            return {true, true};
        auto lres = check(root->left, height - 1);
        if (!lres.first)
            return {false, false};
        if (lres.second) {
            auto rres = check(root->right, height-1);
            if (rres.first)
                return {true, rres.second};
            else {
                rres = check(root->right, height-2);
                return {rres.first, false};
            }
        }

        auto rres = check(root->right, height-2);
        return {rres.first && rres.second && !check(root->right, height-1).first, false};
    }

    int get_height(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(get_height(root->left), get_height(root->right));
    }

    int isCompleteTree(TreeNode* root) {
        if (!root)
            return true;

        return check(root, get_height(root)).first;
    }
};

int main() {
    Solution sol;

    return 0;
}
