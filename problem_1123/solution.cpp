/*
1123. Lowest Common Ancestor of Deepest Leaves
Medium

Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:
The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.

Example 1:
Input: root = [1,2,3]
Output: [1,2,3]
Explanation: 
The deepest leaves are the nodes with values 2 and 3.
The lowest common ancestor of these leaves is the node with value 1.
The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".

Example 2:
Input: root = [1,2,3,4]
Output: [4]

Example 3:
Input: root = [1,2,3,4,5]
Output: [2,4,5]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
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

struct Entry {
    TreeNode* node;
    vector<TreeNode*> path;
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        array<vector<Entry>, 2> rows;
        Entry e{root, vector<TreeNode*>{root}};
        rows[0].emplace_back(e);
        int curr = 0, next;

        while (!rows[curr].empty()) {
            next = 1 - curr;
            rows[next].clear();
            for (auto& e: rows[curr]) {
                if (!e.node->left && !e.node->right)
                    continue;
                Entry new_e(e);
                for (auto child : {e.node->left, e.node->right}) {
                    if (child) {
                        new_e.node = child;
                        new_e.path.emplace_back(child);
                        rows[next].emplace_back(new_e);
                        new_e.path.pop_back();
                    }
                }
            }
            curr = next;
        }

        next = 1 - curr;
        if (rows[next].empty())
            abort();

        TreeNode* candidate = root;
        size_t path_len = rows[next][0].path.size();
        size_t row_size = rows[next].size();
        if (row_size == 1)
            return rows[next][0].path[path_len-1];
        for (size_t i = 1; i < path_len-1; ++i) {
            bool match = true;
            for (size_t j = 1; match && j < row_size; ++j) {
                if (rows[next][0].path[i] != rows[next][j].path[i])
                    match = false;
            }
            if (match)
                candidate = rows[next][0].path[i];
            else
                break;
        }

        return candidate;
    }
};

int main() {
    Solution sol;
    int N = 100;
    vector<TreeNode> nodes;

    for (int i = 0; i < N; ++i)
        nodes.emplace_back(i+1);

    // [1,null,2,null,3,null,4,null,5]
    // Expected: 5
    /*
    nodes[0].right = &nodes[1];
    nodes[1].right = &nodes[2];
    nodes[2].right = &nodes[3];
    nodes[3].right = &nodes[4];
    */

    // [1,2,3,4]
    // Expected: 4
    /*
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];
    */

    // [1,2,3]
    // Expected: 1
    /*
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    */

    // [1,2,null,3,4,null,6,null,5]
    // Expected: 2
    nodes[0].left = &nodes[1];
    nodes[1].left = &nodes[2];
    nodes[1].right = &nodes[3];
    nodes[2].right = &nodes[5];
    nodes[3].right = &nodes[4];

    TreeNode* res = sol.lcaDeepestLeaves(&nodes[0]);

    cout << "Result: " << res->val << endl;

    return 0;
}

