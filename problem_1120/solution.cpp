/*
1120. Maximum Average Subtree
User Accepted: 674
User Tried: 734
Total Accepted: 701
Total Submissions: 1201
Difficulty: Medium
Given the root of a binary tree, find the maximum average value of
any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average
value of a tree is the sum of its values, divided by the number of nodes.)

Example 1:
Input: [5,6,1]
Output: 6.00000

Explanation: 
For the node with value = 5 we have and average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have and average of 6 / 1 = 6.
For the node with value = 1 we have and average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    pair<int, int> visit(TreeNode* node) {
        int sum = node->val;
        int nodes = 1;

        if (node->left) {
            int left_sum, left_nodes;
            tie(left_sum, left_nodes) = visit(node->left);
            sum += left_sum;
            nodes += left_nodes;
        }

        if (node->right) {
            int right_sum, right_nodes;
            tie(right_sum, right_nodes) = visit(node->right);
            sum += right_sum;
            nodes += right_nodes;
        }
        res = max(res, static_cast<double>(sum) / nodes);

        return {sum, nodes};
    }

    double maximumAverageSubtree(TreeNode* root) {
        visit(root);
        return res;
    }

    double res = 0.0;
};

int main() {
    Solution sol;

    return 0;
}

