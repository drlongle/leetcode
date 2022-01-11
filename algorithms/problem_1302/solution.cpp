/*
1302. Deepest Leaves Sum
Medium

Given a binary tree, return the sum of values of its deepest leaves.

Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
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
};

class Solution {
public:
    void getLeaves(TreeNode* root, int level) {
        if (!root)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leaves.emplace_back(level, root->val);
        maxLevel = max(level, maxLevel);
        getLeaves(root->left, level + 1);
        getLeaves(root->right, level + 1);
    }
    
    vector<pair<int, int>> leaves;
    int maxLevel;
    
    int deepestLeavesSum(TreeNode* root) {
        maxLevel = 0;
        getLeaves(root, 0);
        auto lambda = [=] (const int& sum, const pair<int, int>& leave) { return sum + (leave.first == maxLevel ? leave.second : 0);};
        return std::accumulate(leaves.begin(), leaves.end(), 0, lambda);
    }
};

class Solution2 {
public:
    void getLeaves(TreeNode* root, int level) {
        if (!root)
            return;
        if (root->left == nullptr && root->right == nullptr && level == maxLevel)
            sum += root->val;
        getLeaves(root->left, level + 1);
        getLeaves(root->right, level + 1);
    }

    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    int maxLevel, sum;
    
    int deepestLeavesSum(TreeNode* root) {
        maxLevel = getHeight(root);
        sum = 0;
        getLeaves(root, 1);
        return sum;
    }
};

int main() {
    Solution sol;
    return 0;
}
