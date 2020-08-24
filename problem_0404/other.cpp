class Solution {
public:
    int sum;
    
    bool is_leaf(TreeNode* node) {
        return node && !node->left  && !node->right;
    }
    void visit(TreeNode* node) {
        if (!node)
            return;
        if (is_leaf(node->left)) {
            sum += node->left->val;
        } else
            visit(node->left);
        visit(node->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        visit(root);
        
        return sum;
    }
};
