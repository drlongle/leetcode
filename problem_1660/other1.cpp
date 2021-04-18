class Solution {
public:
    unordered_set<int> set;
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->right && set.count(root->right->val)) return NULL;
        set.insert(root->val);
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);
        return root;
    }
};
