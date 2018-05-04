vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    deque<TreeNode*> node;
    int level = 0;
    if (root == nullptr) {
        return ret;
    }
    node.push_back(root);
    while (node.size() != 0) {
        int toBePop = node.size();
        vector<int> v;
        while (toBePop--) {
            TreeNode * n = node.front();
            v.push_back(n->val);
            if (n->left != nullptr) {
                node.push_back(n->left);
            }
            if (n->right != nullptr) {
                node.push_back(n->right);
            }
            node.pop_front();
        }
        ret.push_back(v);
    }
    return ret;
}

