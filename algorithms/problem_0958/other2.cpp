bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool bNullSeen = false;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur)
                bNullSeen = true;
            else if (bNullSeen && cur)
                return false;
            else {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
    }
    return true;
}
