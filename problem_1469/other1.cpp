class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        getLonelyNodes(root, ans);
        return ans;
    }

private:
    void getLonelyNodes(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        if ((root->left) && !(root->right) || !(root->left) && (root->right)) {
            ans.push_back(!(root->left) ? root->right->val : root->left->val);
        }
        if (root->left) {
            getLonelyNodes(root->left, ans);
        }
        if (root->right) {
            getLonelyNodes(root->right, ans);
        }
    }
};
