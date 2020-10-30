/*
652. Find Duplicate Subtrees
Medium

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:
The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<string, vector<TreeNode*>> table;

    string visit(TreeNode* node) {
        if (!node)
            return "";
        ostringstream oss;
        oss << node->val << "-" << visit(node->left) << "-" << visit(node->right);
        auto s = oss.str();
        table[s].emplace_back(node);

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        visit(root);
        for (auto& [k, vect]: table) {
            if (vect.size() > 1) {
                res.emplace_back(vect[0]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
