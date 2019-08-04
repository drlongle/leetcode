/*
1145. Binary Tree Coloring Game
Medium

Two players play a turn based game on a binary tree. We are given the root
of this binary tree, and the number of nodes n in the tree. n is odd, and
each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second
player names a value y with 1 <= y <= n and y != x.  The first player colors
the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player.  In each turn,
that player chooses a node of their color (red if player 1, blue if player 2)
and colors an uncolored neighbor of the chosen node (either the left child,
right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must
pass their turn.  If both players pass their turn, the game ends, and the
winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure
you win the game, return true.  If it is not possible, return false.
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
    TreeNode* get_node(TreeNode* root, int label)
    {
        if (root->val == label)
            return root;
        if (root->left) {
            auto ls = get_node(root->left, label);
            if (ls)
                return ls;
        }
        if (root->right) {
            auto rs = get_node(root->right, label);
            if (rs)
                return rs;
        }
        return nullptr;
    }

    int count_nodes(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x)
    {
        auto node = get_node(root, x);
        if (count_nodes(node->left) > n / 2 || count_nodes(node->right) > n / 2)
            return true;
        int count = count_nodes(node);
        return n - count > count;
    }
};

int main()
{
    Solution sol;
    vector<TreeNode> nodes;
    int n, x;

    for (int i = 0; i <= 20; ++i) {
        nodes.emplace_back(i);
    }

    // Expected: true
    n = 11, x = 3;

    cout << "Result: " << sol.btreeGameWinningMove(&nodes[1], n, x) << endl;

    return 0;
}
