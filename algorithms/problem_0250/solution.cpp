/*
250. Count Univalue Subtrees
Medium

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

Example 1:
Input: root = [5,1,5,5,5,null,5]
Output: 4

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [5,5,5,5,5,null,5]
Output: 6

Constraints:
The numbers of the nodes in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
Accepted
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
    int res=0;
    bool dfs(TreeNode *node){
        if (!node) return true;
        bool l = dfs(node->left);
        bool r = dfs(node->right);
        bool s = l&&r;
        s &= !node->left|| (node->val==node->left->val);
        s &= !node->right ||(node->val==node->right->val);
        res+=s;
        return s;
    }

    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
