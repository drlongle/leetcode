/*
We know that a binary tree can be represented by an array (assume the root begins
from the position with index 1 in the array). If the index of a node is i, the indices
of its two children are 2*i and 2*i + 1. The idea is to use two arrays (start[] and end[])
to record the the indices of the leftmost node and rightmost node in each level, respectively.
For each level of the tree, the width is end[level] - start[level] + 1. Then, we just
need to find the maximum width.
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root, 0, 1, vector<pair<int, int>>() = {});
    }
    
    int dfs(TreeNode* root, int level, int order, vector<pair<int, int>>& vec){
        if(root == NULL)return 0;
        if(vec.size() == level)vec.push_back({order, order});
        else vec[level].second = order;
        return max({vec[level].second - vec[level].first + 1,
            dfs(root->left, level + 1, 2*order, vec),
            dfs(root->right, level + 1, 2*order + 1, vec)});
    }
};