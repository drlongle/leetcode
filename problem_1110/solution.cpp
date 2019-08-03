/*
1110. Delete Nodes And Return Forest
Medium

Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a
forest (a disjoint union of trees). Return the roots of the trees in the
remaining forest.  You may return the result in any order.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution {
public:
    void del_nodes(TreeNode* root)
    {
        bool delete_root = del.count(root->val);
        if (root->left) {
            del_nodes(root->left);
            if (del.count(root->left->val)) {
                root->left = nullptr;
            } else if (delete_root)
                res.emplace_back(root->left);
        }
        if (root->right) {
            del_nodes(root->right);
            if (del.count(root->right->val)) {
                root->right = nullptr;
            } else if (delete_root)
                res.emplace_back(root->right);
        }
    }

    vector<TreeNode*> res;
    unordered_set<int> del;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        res.clear();
        del.clear();
        for (auto d : to_delete)
            del.emplace(d);

        if (!root)
            return res;
        del_nodes(root);
        if (del.count(root->val) == 0) {
            res.emplace_back(root);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<TreeNode> nodes;
    vector<int> to_delete;
    for (int i = 0; i < 10; ++i)
        nodes.emplace_back(i);

    nodes[1].left = &nodes[2];
    nodes[1].right = &nodes[3];
    nodes[2].left = &nodes[4];
    nodes[2].right = &nodes[5];
    nodes[3].left = &nodes[6];
    nodes[3].right = &nodes[7];
    to_delete = {3, 5};

    sol.delNodes(&nodes[1], to_delete);

    return 0;
}
