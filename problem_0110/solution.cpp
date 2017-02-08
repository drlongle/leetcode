/*
110. Balanced Binary Tree
Total Accepted: 114900 Total Submissions: 334672 Difficulty: Easy

Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

pair<bool,int> is_balanced(TreeNode* node)
{
    if (!node) return {true,0};
    pair<bool, int> lres = is_balanced(node->left);
    pair<bool, int> rres = is_balanced(node->right);
    pair<bool,int> res =
        {lres.first && rres.first, 1 + max(lres.second,rres.second)};
    if (abs(lres.second-rres.second) > 1) res.first = false;
    return res;
}

class Solution {
public:
    bool isBalanced(TreeNode* node) {
        if (!node) return true;
        pair<bool, int> res = is_balanced(node);
        return res.first;
    }
};

int main()
{
    Solution sol;

    return 0;
}

