class Solution {
public:
    int maxSum = 0;
    int dfs(TreeNode* n) {
        if (n == nullptr) return 0;
        auto ls = dfs(n->left), rs = dfs(n->right);
        if (ls != INT_MIN && rs != INT_MIN) {
            if ((n->left == nullptr || n->left->val < n->val) 
                && (n->right == nullptr || n->right->val > n->val)) {
                maxSum = max(maxSum, n->val + ls + rs);
                return n->val + ls + rs;
            }
        }
        return INT_MIN;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
