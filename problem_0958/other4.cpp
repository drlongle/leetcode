class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);

        TreeNode* last = root;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front(); q.pop();

                if (!last && cur) return false;
                else last = cur;

                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }

        return true;
    }
};
