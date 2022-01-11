class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        if(!root)
            return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 and root->left == NULL and root->right == NULL)
            return NULL;
        return root;
    }
};
