/*
1602. Find Nearest Right Node in Binary Tree
Medium

Given the root of a binary tree and a node u in the tree, return the nearest node on the same
level that is to the right of u, or return null if u is the rightmost node in its level.

Example 1:
Input: root = [1,2,3,null,4,5,6], u = 4
Output: 5
Explanation: The nearest node on the same level to the right of node 4 is node 5.

Example 2:
Input: root = [3,null,4,2], u = 2
Output: null
Explanation: There are no nodes to the right of 2.

Example 3:
Input: root = [1], u = 1
Output: null

Example 4:
Input: root = [3,4,2,null,null,null,1], u = 4
Output: 2

Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All values in the tree are distinct.
u is a node in the binary tree rooted at root.
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode* res = nullptr;
        array<vector<TreeNode*>, 2> visited;
        visited[0].emplace_back(root);
        int curr = 0, next;
        bool found = false;
        do {
            next = 1 - curr;
            visited[next].clear();
            for (auto node: visited[curr]) {
                if (found && !res)
                    res = node;
                found = node == u;
                if (node->left)
                    visited[next].emplace_back(node->left);
                if (node->right)
                    visited[next].emplace_back(node->right);
                curr = next;
            }
        } while (visited[next].size() && !found);

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
