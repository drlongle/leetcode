/*
1373. Maximum Sum BST in Binary Tree
Hard

Given a binary tree root, the task is to return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

Example 3:
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.

Example 4:
Input: root = [2,1,3]
Output: 6

Example 5:
Input: root = [5,4,8,3,null,6,3]
Output: 7

Constraints:
Each tree has at most 40000 nodes..
Each node's value is between [-4 * 10^4 , 4 * 10^4].
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
#include <memory>
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

class Solution {
public:
    struct Result {
        int min, max, sum;
        bool bst;
    };
    
    int result;

    Result visit(TreeNode* node) {
        Result res;
        res.bst = true;
        if (node == nullptr) {
            res.sum = 0;
            return res;
        }

        res.min = node->val;
        res.max = node->val;
        res.sum = node->val;
        if (node->left) {
            auto lres = visit(node->left);
            if (lres.max >= node->val || !lres.bst)
                res.bst = false;
            else
                res.sum += lres.sum;
            res.min = min(res.min, lres.min);
            res.max = max(res.max, lres.max);
        }
        if (node->right) {
            auto rres = visit(node->right);
            if (rres.min <= node->val || !rres.bst)
                res.bst = false;
            else
                res.sum += rres.sum;
            res.min = min(res.min, rres.min);
            res.max = max(res.max, rres.max);
        }
        if (res.bst) {
            result = max(res.sum, result);
        }

        return res;
    }
    
    int maxSumBST(TreeNode* root) {
        result = 0;
        visit(root);
        return result;
    }
};

void test_9()
{
    // Output: 2
    // [4,3,null,1,2]
    Solution sol;

}

void test_12()
{
    // Output: 6
    // [2,1,3]
    Solution sol;

}

void test_51()
{
    // Expected: 14
    // [9,2,3,null,2,null,null,3,null,-5,4,null,1,null,10]
    //vector<TreeNode> nodes(8, 0);
    vector<TreeNode> nodes{9,2,3,2,3,-5,4,10};
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].right = &nodes[3];
    nodes[3].left = &nodes[4];
    nodes[4].left = &nodes[5];
    nodes[4].right = &nodes[6];
    nodes[6].right = &nodes[7];
    
    Solution sol;
    cout << sol.maxSumBST(&nodes[0]) << endl;
}

void test_52()
{
    // Expected: 11
    //[8,9,8,null,9,null,1,null,null,-3,5,null,-2,null,6]
    Solution sol;
    vector<TreeNode> nodes{8,9,8,9,1,-3,5,-2,6};
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].right = &nodes[3];
    nodes[3].left = &nodes[4];
    nodes[4].left = &nodes[5];
    nodes[4].right = &nodes[6];
    nodes[6].right = &nodes[7];
    
    cout << sol.maxSumBST(&nodes[0]) << endl;
}

int main() {
    test_51();
    test_52();
    return 0;
}
