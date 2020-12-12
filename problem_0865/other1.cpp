class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) return NULL;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (left == right) return root;
        else if (left > right) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
    }

private :
    int getDepth(TreeNode* node)
    {
        if (node == NULL) return 0;
        return 1 + std::max(getDepth(node->left),getDepth(node->right));
    }
};
