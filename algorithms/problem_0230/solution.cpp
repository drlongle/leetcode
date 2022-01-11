/*
230. Kth Smallest Element in a BST  
Total Accepted: 44592 Total Submissions: 118625 Difficulty: Medium

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. 
You may assume k is always valid, 1 <= k <= BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int getSize(TreeNode* node) {
        int count = 1;
        if (node->left)
            count += getSize(node->left);
        if (node->right)
            count += getSize(node->right);
        return count;
    }

    int kthSmallest(TreeNode* root, int k) {
        int leftsize = 0;
        if (root->left)
            leftsize = getSize(root->left);
        if (leftsize + 1 == k)
            return root->val;
        if (leftsize >= k)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k-leftsize-1);
    }
};

int main()
{
    Solution sol;

    return 0;
}

