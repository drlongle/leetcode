class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return NULL;

        TreeNode* temp = NULL, *prev = NULL, *next = NULL;
        TreeNode* curr = root;

        while (curr) {
            next = curr->left;
            curr->left = temp;
            temp = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
