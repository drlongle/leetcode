/*
742. Closest Leaf in a Binary Tree
Medium

Given a binary tree where every node has a unique value, and a target key k, find the value
of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach
any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row.
The actual root tree given will be a TreeNode object.

Example 1:
Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.

Example 2:
Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.

Example 3:
Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the
node with value 2.

Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.
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

    unordered_map<int, pair<bool, vector<int>>> graph;
    unordered_set<int> visited;
    queue<int> q;

    void DFS(TreeNode *node, int k) {
        int id = node->val;
        if (id == k)
            q.push(id);
        graph[id].first = !node->left && !node->right;

        if (node->left) {
            graph[id].second.push_back(node->left->val);
            graph[node->left->val].second.push_back(id);
            DFS(node->left, k);
        }

        if (node->right) {
            graph[id].second.push_back(node->right->val);
            graph[node->right->val].second.push_back(id);
            DFS(node->right, k);
        }
    }

    int findClosestLeaf(TreeNode* root, int k) {
        DFS(root, k);
        while (!q.empty()) {
            int id = q.front();
            visited.emplace(id);
            q.pop();
            if (graph[id].first)
                return id;
            for (int nid: graph[id].second) {
                if (!visited.count(nid))
                    q.push(nid);
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}
