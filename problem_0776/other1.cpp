class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root) return {nullptr,nullptr};
        if(V >= root->val) {
            auto v{splitBST(root->right, V)};
            root->right = v[0];
            return {root, v[1]};
        } else {
            auto v{splitBST(root->left, V)};
            root->left = v[1];
            return {v[0], root};
        }
    }
};
