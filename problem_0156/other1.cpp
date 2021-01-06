class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || (root && !root->left))
            return root;

        TreeNode* new_root = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;

        root->left = nullptr;
        root->right = nullptr;

        return new_root;
    }
};
