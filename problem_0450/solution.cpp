/*
450. Delete Node in a BST
Medium

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


void fixTreeLeft(TreeNode* parent, TreeNode* child) {
    TreeNode* left = child->left;
    TreeNode* right = child->right;
    if (!right) {
        parent->left = left;
        return;
    }
    if (!left) {
        parent->left = right;
        return;
    }
    parent->left = left;
    while (left->right)
        left = left->right;
    left->right = right;
}

void fixTreeRight(TreeNode* parent, TreeNode* child) {
    TreeNode* left = child->left;
    TreeNode* right = child->right;
    if (!left) {
        parent->right = right;
        return;
    }
    if (!right) {
        parent->right = left;
        return;
    }
    parent->right = right;
    while (right->left)
        right = right->left;
    right->left = left;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (root->left) {
                fixTreeLeft(root, root);
                return root->left;
            } else if (root->right) {
                fixTreeRight(root, root);
                return root->right;
            } else
                return nullptr;
        }
        TreeNode *parent = root;
        while (parent) {
            if (parent->left && parent->left->val == key) {
                fixTreeLeft(parent, parent->left);
                break;
            } else if (parent->right && parent->right->val == key) {
                fixTreeRight(parent, parent->right);
                break;
            }
            parent = parent->val > key ? parent->left : parent->right;
        }
        
        return root;
    }
};

void printTree(TreeNode* node)
{
    if (!node) {
        cout << " NULL ";
        return;
    }
    printTree(node->left);
    cout << " " << node->val << " ";
    printTree(node->right);
}

/*
Tree: [1,null,2]
Key: 2
Expected: [1]
 */
void test_37() {
    Solution sol;
    TreeNode right(2);
    TreeNode root(1);
    root.right = &right;
    auto res = sol.deleteNode(&root, 2);
    cout << "Result: " << res->val << endl;
}

/*
Tree: [3,1,4,null,2]
Key: 3
Expected: [1,2,4]
 */
void test_66() {
    Solution sol;
    vector<TreeNode> nodes{3, 1, 4, 2};
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].right = &nodes[3];
    int key = 3;
    auto res = sol.deleteNode(&nodes[0], key);
    printTree(res);
    cout << endl;
}

/*
[5,3,6,1,4,null,null,null,2]
3
Expected:: [5,4,6,1,null,null,null,null,2]
 */
void test_73() {
    Solution sol;
    vector<TreeNode> nodes{5, 3, 6, 1, 4, 2};
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[2];
    nodes[3].right = &nodes[4];
    int key = 3;
    auto res = sol.deleteNode(&nodes[0], key);
    printTree(res);
    cout << endl;
}

int main() {
    //test_37();
    //test_66();
    test_73();
    return 0;
}
