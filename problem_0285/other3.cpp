class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // Try with level-order traversal.
        queue<TreeNode*> q;
        q.push(root);
        int diff = INT_MAX;
        TreeNode* ans = nullptr;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            int difference = node->val - p->val;
            if (difference > 0 and node != p and difference < diff) {
                diff = difference; ans = node;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return ans;
    }
};
