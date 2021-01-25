/*
63. All Nodes Distance K in Binary Tree
Medium

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.
The answer can be returned in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
Explanation:
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:
The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, unordered_set<TreeNode*>> g;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(root, nullptr);
        while (!q.empty()) {
            auto& [node, parent] = q.front();
            if (parent) {
                g[node].emplace(parent);
                g[parent].emplace(node);
            }
            if (node->left)
                q.emplace(node->left, node);
            if (node->right)
                q.emplace(node->right, node);
            q.pop();
        }

        vector<int> res;
        unordered_set<TreeNode*> visited;

        queue<pair<TreeNode*, int>> qq;
        qq.emplace(target, 0);
        visited.emplace(target);
        while (qq.size()) {
            auto& p = qq.front();
            if (p.second < K) {
                for (auto nei: g[p.first]) {
                    if (visited.emplace(nei).second) {
                        qq.emplace(nei, p.second+1);
                    }
                }
            } else if (p.second == K)
                res.push_back(p.first->val);
            qq.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
