/*
979. Distribute Coins in Binary Tree
Difficulty: Medium

Given the root of a binary tree with N nodes, each node in the tree has node.val
coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node
to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int balance(TreeNode* node, int& nodes, int& val) {
        int res = 0;
        if (node->left) {
            int temp1 = 0, temp2 = 0;
            res += balance(node->left, temp1, temp2);
            res += abs(temp1 - temp2);
            nodes += temp1;
            val += temp2;
        }
        if (node->right) {
            int temp1 = 0, temp2 = 0;
            res += balance(node->right, temp1, temp2);
            res += abs(temp1 - temp2);
            nodes += temp1;
            val += temp2;
        }
        ++nodes;
        val += node->val;
        
        return res;
    }
    
    int distributeCoins(TreeNode* root) {
        int nodes, val;
        return balance(root, nodes, val);
    }
};

// Expected: 2
TreeNode* test1() {
    vector<TreeNode> nodes{3, 0, 0};
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    Solution sol;
    cout << "test1: " << sol.distributeCoins(&nodes[0]) << endl;
}

// Expected: 6
TreeNode* test2() {
    vector<TreeNode> nodes{4, 0, 0, 0};
    nodes[0].right = &nodes[1];
    nodes[1].right = &nodes[2];
    nodes[2].right = &nodes[3];
    Solution sol;
    cout << "test2: " << sol.distributeCoins(&nodes[0]) << endl;
}

int main(int argc, char** argv) {
    test1();
    test2();
    return 0;
}
