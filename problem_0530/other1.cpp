class Solution {
public:
    int res = INT_MAX, pre = -1;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        if(root->left) res = getMinimumDifference(root->left);
        if(pre >= 0) res = min(res, abs(pre - root->val));
        pre = root->val;
        if(root->right) res = getMinimumDifference(root->right);
        return res;
    }
};
