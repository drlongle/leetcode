/*
589. N-ary Tree Preorder Traversal
Easy

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children
is separated by the null value (See examples)

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

Constraints:
The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 10^4
The height of the n-ary tree is less than or equal to 1000.

Follow up: Recursive solution is trivial, could you do it iteratively
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<pair<Node*, int>> nodes;
        vector<int> res;
        if (!root)
            return res;

        nodes.emplace(root, -1);
        while (nodes.size()) {
            auto& [node, index] = nodes.top();
            if (index < 0) {
                res.push_back(node->val);
                ++index;
            }

            if (index == node->children.size()) {
                nodes.pop();
                continue;
            }
            nodes.emplace(node->children[index++], -1);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
