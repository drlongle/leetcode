/*
298. Binary Tree Longest Consecutive Sequence
Medium

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along
the parent-child connections. The longest consecutive path need to be from parent to child
(cannot be the reverse).

Example 1:
Input:
   1
    \
     3
    / \
   2   4
        \
         5
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.

Example 2:
Input:
   2
    \
     3
    /
   2
  /
 1
Output: 2
Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int visit(TreeNode* root) {
        if (!root)
            return 0;
        int l = visit(root->left);
        int res = l && root->val +1 == root->left-> val ? l + 1 : 1;
        int r  = visit(root->right);
        if (r && root->val +1 == root->right->val)
            res = max(res, r +1);
        longest = max(res, longest);
        return res;
    }

    int longest = 0;

    int longestConsecutive (TreeNode* root) {
        visit(root);
        return longest;
    }
};

int main() {
    Solution sol;

    return 0;
}
