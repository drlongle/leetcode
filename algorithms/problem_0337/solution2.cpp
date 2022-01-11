class Solution {
public:
    vector<unordered_map<TreeNode*, int>> cache;

    int rob(TreeNode* root) {
        cache.resize(2);
        return rob(root, true);
    }
    int rob(TreeNode* root, int allowed) {
        if (!root)
            return 0;
        auto it = cache[allowed].find(root);
        if (it != cache[allowed].end())
            return it->second;
        int res = rob(root->left, true) + rob(root->right, true);
        if (allowed) {
            res = max(res, root->val + rob(root->left, false) + rob(root->right, false));
        }
        return cache[allowed][root] = res;
    }
};