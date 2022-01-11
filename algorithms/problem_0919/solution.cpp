/*
919. Complete Binary Tree Inserter
Medium

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.

Example 1:
Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]

Example 2:
Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]

Note:
The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class CBTInserter {
public:
    vector<TreeNode*> curr, next;
    TreeNode* root;
    int index;
    
    ~CBTInserter() {delete root;}
    
    CBTInserter(TreeNode* r): root(r), index(0) {
        curr.emplace_back(root);
        while (true) {
            for (TreeNode* node: curr) {
                if (node->left && node->right)
                    ++index;
                if (node->left)
                    next.emplace_back(node->left);
                if (node->right)
                    next.emplace_back(node->right);
            }
            if (next.size() != curr.size() * 2)
                break;
            else
                reset();
        }
    }

    void reset() {
        swap(curr, next);
        next.clear();
        index = 0;
    }
    
    int insert(int v) {
        TreeNode* node = curr[index];
        int res = node->val;
        TreeNode* child = new TreeNode(v);
        next.emplace_back(child);
        if (node->left == nullptr)
            node->left = child;
        else {
            node->right = child;
            ++index;
        }
        if (next.size() == curr.size() * 2)
            reset();
        return res;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

void test_0()
{
    CBTInserter cbt(new TreeNode(1));
    cbt.insert(2);
}

void test_1()
{
    /*
      ["CBTInserter","insert","insert","get_root"]
      [[[1,2,3,4,5,6]],[7],[8],[]]
    */
    vector<TreeNode*> nodes;
    for (int i = 0; i <= 6; ++i)
        nodes.emplace_back(new TreeNode(i));
    nodes[1]->left = nodes[2];
    nodes[1]->right = nodes[3];
    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];
    nodes[3]->left = nodes[6];
    CBTInserter cbt(nodes[1]);
    cbt.insert(7);
    cbt.insert(8);
}

int main() {
    test_1();
    return 0;
}
