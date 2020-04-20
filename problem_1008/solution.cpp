/*
1008. Construct Binary Search Tree from Preorder Traversal
Medium

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
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
    TreeNode* build(vector<int>& preorder, int min, int max) {
        if (index >= sz)
            return nullptr;
        int val = preorder[index];
        if (val >= max || val <= min)
            return nullptr;
        TreeNode* node = new TreeNode(val);
        ++index;
        node->left = build(preorder, min, val);
        node->right = build(preorder, val, max);

        return node;
    }

    size_t index, sz;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        index = 0;
        sz = preorder.size();
        return build(preorder, numeric_limits<int>::min(),  numeric_limits<int>::max());
    }
};

void test_1() {
    Solution sol;
    vector<int> preorder;

    preorder = {8,5,1,7,10,12};
    sol.bstFromPreorder(preorder);
}

int main() {
    test_1();
    return 0;
}
