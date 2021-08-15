/*
549. Binary Tree Longest Consecutive Sequence II
Medium

Given the root of a binary tree, return the length of the longest consecutive path in the tree.

A consecutive path is a path where the values of the consecutive nodes in the path differ by one.
This path can be either increasing or decreasing.

For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].

Example 2:
Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].

Constraints:
The number of nodes in the tree is in the range [1, 3 * 10^4].
-3 * 10^4 <= Node.val <= 3 * 10^4
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

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    int res = 0;

    pair<int,int> visit(TreeNode *node) {
        pair<int,int> ans{1,1};
        if (!node)
            return {0,0};
        auto lr = visit(node->left);
        auto rr = visit(node->right);
        if (node->left) {
            int diff = node->val - node->left->val;
            if(diff == -1) {
                ans.first = 1 + lr.first;
            } else if (diff == 1) {
                ans.second = 1 + lr.second;
            }
        }
        if (node->right) {
            int diff = node->val - node->right->val;
            if (diff == -1) {
                ans.first = max(ans.first, 1 + rr.first);
            } else if (diff == 1) {
                ans.second = max(ans.second, 1 + rr.second);
            }
        }
        if (node->left && node->right) {
            int ldiff = node->val - node->left->val;
            int rdiff = node->val - node->right->val;
            if (ldiff == -1 && rdiff == 1)
                res = max(res, rr.second + 1 + lr.first);
            if (ldiff == 1 && rdiff == -1)
                res = max(res, rr.first + 1 + lr.second);
        }
        res = max({res, ans.first, ans.second, lr.first, lr.second, rr.first, rr.second});

        return ans;
    }

    int longestConsecutive(TreeNode* root) {
        visit(root);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
