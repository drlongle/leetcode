class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int res = helper(root, 1) + helper(root, -1) + 1;
        return max({res, longestConsecutive(root->left), longestConsecutive(root->right)});
    }

    int helper(TreeNode* root, int diff){
        if(!root) return 0;
        int left = 0, right = 0;
        if(root->left && root->left->val - root->val == diff) left = helper(root->left, diff) + 1;
        if(root->right && root->right->val - root->val == diff) right = helper(root->right, diff) + 1;
        return max(left, right);
    }
};
