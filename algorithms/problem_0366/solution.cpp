/*
366. Find Leaves of Binary Tree
Medium

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.

Example 1:
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it
does not matter the order on which elements are returned.

Example 2:
Input: root = [1]
Output: [[1]]

Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
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
    vector<vector<int>> res;

    bool dfs(TreeNode* node){
        if (!node->left && !node->right) {
            res.back().push_back(node->val);
            return true;
        }

        if (node->left && dfs(node->left))
            node->left = 0;
        if (node->right && dfs(node->right))
            node->right = 0;
        return false;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        while (true) {
            res.emplace_back(vector<int>());
            if (!root->left && !root->right) {
                res.back().push_back(root->val);
                break;
            } else
                dfs(root);
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
