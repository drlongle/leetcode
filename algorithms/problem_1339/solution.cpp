/*
1339. Maximum Product of Splitted Binary Tree
Medium

Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7. 

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Example 3:
Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025

Example 4:
Input: root = [1,1]
Output: 1

Constraints:

Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    using ll = long long;
    static constexpr ll mod_const = 1000000007;
    void visit(TreeNode* node) {
        ll local_sum = sum[node];
        res = max(res, local_sum * (total_sum - local_sum));
        if (node->left)
            visit(node->left);
        if (node->right)
            visit(node->right);
    }

    unordered_map<TreeNode*, ll> sum;
    ll total_sum, res;
    ll get_sum(TreeNode* root) {
        ll local_sum = root->val;
        if (root->left)
            local_sum = (local_sum + get_sum(root->left));
        if (root->right)
            local_sum = (local_sum + get_sum(root->right));
        sum[root] = local_sum;
        return local_sum;
    }
    
    ll maxProduct(TreeNode* root) {
        res = 0;
        total_sum = get_sum(root);
        visit(root);
        return res % mod_const;
    }
};

void test_1() {
    Solution sol;
    int N = 7;
    vector<TreeNode> nodes(N, 0);

    for (int i = 0; i < N; ++i)
        nodes[i].val = i;

    nodes[1].left = &nodes[2];
    nodes[1].right = &nodes[3];

    nodes[2].left = &nodes[4];
    nodes[2].right = &nodes[5];
    nodes[3].left = &nodes[6];

    // Output: 110
    cout << "Result: " << sol.maxProduct(&nodes[1]) << endl;
}

void test_2() {
    Solution sol;
    int N = 7;
    vector<TreeNode> nodes(N, 0);

    for (int i = 0; i < N; ++i)
        nodes[i].val = i;
    
    nodes[1].right = &nodes[2];
    nodes[2].left = &nodes[3];
    nodes[2].right = &nodes[4];
    nodes[4].left = &nodes[5];
    nodes[4].right = &nodes[6];

    // Output: 90
    cout << "Result: " << sol.maxProduct(&nodes[1]) << endl;
}

void test_3() {
    Solution sol;
    vector<TreeNode> nodes{2,3,9,10,7,8,6,5,4,11,1};
    
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];
    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];
    nodes[3].left = &nodes[7];
    nodes[3].right = &nodes[8];
    nodes[4].left = &nodes[9];
    nodes[4].right = &nodes[10];
    
    // Output: 1025
    cout << "Result: " << sol.maxProduct(&nodes[0]) << endl;
}

void test_4() {
    Solution sol;
    vector<TreeNode> nodes{1,1};
    
    nodes[0].left = &nodes[1];
    
    // Output: 1
    cout << "Result: " << sol.maxProduct(&nodes[0]) << endl;
}

void test_14() {
    Solution sol;
    vector<TreeNode> nodes{5,6,6,8,6,10,5};
    
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[2].left = &nodes[3];
    nodes[2].right = &nodes[4];
    nodes[3].left = &nodes[5];
    nodes[4].left = &nodes[6];
    
    // Output: 504
    cout << "Result: " << sol.maxProduct(&nodes[0]) << endl;
}

int main() {
    test_1();
    //test_2();
    //test_3();
    //test_4();

    //test_14();
    
    return 0;
}
