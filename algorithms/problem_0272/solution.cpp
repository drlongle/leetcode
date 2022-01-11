/*
272. Closest Binary Search Tree Value II
Hard

Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST
that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Example 1:
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]

Example 2:
Input: root = [1], target = 0.000000, k = 1
Output: [1]

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 10^4.
0 <= Node.val <= 10^9
-10^9 <= target <= 10^9

Follow up: Assume that the BST is balanced. Could you solve it in less than O(n) runtime (where n = total nodes)?
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

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        auto lambda = [target] (int a, int b) {return abs(target-a) >= abs(target-b);};
        set<int, decltype(lambda)> nums(lambda);

        function<void(TreeNode*)> dfs = [&] (TreeNode* node) {
            if (!node)
                return;
            nums.insert(node->val);
            while (nums.size() > k)
                nums.erase(nums.begin());
            if (nums.size() >= k) {
                if (node->val - target <= *nums.begin())
                    dfs(node->right);
                if (target - node->val <= *nums.begin())
                    dfs(node->left);
            } else {
                dfs(node->left);
                dfs(node->right);
            }
        };

        dfs(root);
        vector <int> res(nums.begin(), nums.end());
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
