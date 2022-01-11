class Solution {
public:
    int cnt{0};
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = dfs(root, p, q);
        return cnt == 2 ? res : nullptr;
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);
        if(left and right) return root;
        if(root == p or root == q){
            cnt++;
            return root;
        }
        return left != nullptr ? left : right;
    }
};
