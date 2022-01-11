class Solution {
    vector<int> res;
    void helper(TreeNode* node, bool left) {
        if (!node)
            return;
        if (left)
            res.push_back(node->val);
        helper(node->left,true && left);
        helper(node->right,left && !(node->left));
        if (!left && !(node->left) && !(node->right))
            res.push_back(node->val);
    }
    void helper2(TreeNode* node, bool right) {
        if (!node)
            return;
        helper2(node->left,right && !(node->right));
        if (!right && !(node->left) && !(node->right))
            res.push_back(node->val);
        helper2(node->right,true && right);
        if (right)
            res.push_back(node->val);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root)
            return {};
        res.push_back(root->val);
        helper(root->left,true);
        helper2(root->right,true);
        return res;
    }
};
