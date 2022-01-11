/*
129. Sum Root to Leaf Numbers
Total Accepted: 78857 Total Submissions: 238273 Difficulty: Medium

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25. 
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sum_numbers(TreeNode* node, int curr_sum, int& sum)
{
    curr_sum = curr_sum*10 + node->val;
    if (!node->left && !node->right)
    {
        sum += curr_sum;
        return;
    }

    if (node->left)
        sum_numbers(node->left, curr_sum, sum);
    if (node->right)
        sum_numbers(node->right, curr_sum, sum);
}

class Solution {
public:
    int sumNumbers(TreeNode* root);
};

int Solution::sumNumbers(TreeNode* root)
{
    if (!root) return 0;
    int curr_sum = 0, sum = 0;
    sum_numbers(root, curr_sum, sum);

    return sum;
}

int main()
{
    Solution sol;

    return 0;
}

