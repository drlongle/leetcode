/*
663. Equal Tree Partition
Medium

Given the root of a binary tree, return true if you can partition the tree into two trees with equal sums
of values after removing exactly one edge on the original tree.

Example 1:
Input: root = [5,10,10,null,null,2,3]
Output: true

Example 2:
Input: root = [1,2,10,null,null,2,20]
Output: false
Explanation: You cannot split the tree into two trees with equal sums after removing exactly one edge on the tree.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-10^5 <= Node.val <= 10^5
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:

    unordered_map<TreeNode*, int> cache;

    int sum(TreeNode* node){
        if (!node)
            return 0;
        auto it = cache.find(node);
        if (it != cache.end())
            return it->second;
        return cache[node] = node->val + sum(node->left) + sum(node ->right);
    }

    int total;
    TreeNode* root;

    bool visit(TreeNode *node) {
        if (!node)
            return false;

        if (sum(node) * 2 == total && node != root)
            return true;
        return visit(node->left) || visit(node->right);
    }

    bool checkEqualTree(TreeNode* node) {
        root = node;
        total = sum(root);
        return visit(root);
    }
};

int main() {
    Solution sol;

    return 0;
}
