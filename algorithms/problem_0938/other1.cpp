class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val >= L and node->val <=R) ans += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return ans;
    }
};
