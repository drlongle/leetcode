/*
270. Closest Binary Search Tree Value
Easy

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

Example:
Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (root->val == target)
            return root->val;

        if (root->val < target && root->right) {
            int rr = closestValue(root->right, target);
            if (abs(target - rr) < abs(target - res))
                res = rr;
        }
        if (root->val > target && root->left) {
            int lr = closestValue(root->left, target);
            if (abs(target - lr) < abs(target - res))
                res = lr;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
