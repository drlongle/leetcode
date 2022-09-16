class Solution {
  public:
    int res = numeric_limits<int>::min();

    int visit(TreeNode *node) {
        res = max(res, node->val);
        int lr = node->left ? visit(node->left) : 0;
        int rr = node->right ? visit(node->right) : 0;

        int r = max({node->val, node->val + lr, node->val + rr});
        res = max({res, r, node->val + lr + rr});
        return r;
    }

    int maxPathSum(TreeNode *root) {
        if (!root)
            return 0;
        visit(root);
        return res;
    }
};
