class Solution {
public:
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    void flatten(TreeNode* root) {
        if (!root)
            return;

        TreeNode* left = root->left;
        root->left = nullptr;
        TreeNode* right = root->right;
        root->right = nullptr;

        if (!head) {
            head = tail = root;
        } else {
            tail->right = root;
            tail = root;
        }

        flatten(left);
        flatten(right);
    }
};