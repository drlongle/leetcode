/*
337. House Robber III
Total Accepted: 13898 Total Submissions: 36848 Difficulty: Medium

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

     3
    / \
   2   3
    \   \ 
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9. 
*/

#include <algorithm>
#include <array>
#include <cassert>
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

class Solution {
public:
    int robChildren(TreeNode* root)
    {
        if (!root) return 0;
        return rob(root->left) + rob(root->right);
    }

    int rob(TreeNode* root) {
        if (!root) return 0;
        unordered_map<TreeNode*, int>::const_iterator it = m_cache.find(root);
        if (it != m_cache.cend()) return it->second; 
        int val = max(root->val + robChildren(root->left) +
            robChildren(root->right), rob(root->left) + rob(root->right)); 
        m_cache[root] = val;
        return val;
    }

    unordered_map<TreeNode*, int> m_cache;
};

int main()
{
    Solution sol;

    return 0;
}

