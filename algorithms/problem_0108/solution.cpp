/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        return convertToBST(nums, 0, size-1);
    }

    TreeNode* convertToBST(vector<int>& nums, int begin, int end)
    {
        if (begin > end) return NULL;
        int mid = begin + ((end-begin) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convertToBST(nums, begin, mid-1);
        root->right = convertToBST(nums, mid+1, end);
        return root;
    }
};

int main()
{
    return 0;
}
