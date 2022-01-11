class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(root) {
            vector<int> path;
            root = dfs(root, path);
            res.push_back(path);
        }
        return res;
    }

    TreeNode* dfs(TreeNode* root, vector<int>& path) {
        if(!root) return NULL;
        if(!root->left && !root->right) {
            path.push_back(root->val);
            //delete(root);
            return NULL;
        }
        root->left = dfs(root->left, path);
        root->right = dfs(root->right, path);
        return root;
    }
};
