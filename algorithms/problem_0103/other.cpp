class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        if (root)
            q.emplace(root, 1);
        while (q.size()) {
            auto [node, level] = q.front();
            q.pop();
            if (node->left)
                q.emplace(node->left, level+1);
            if (node->right)
                q.emplace(node->right, level+1);
            if (res.size() < level)
                res.emplace_back(vector<int>());
            res[level-1].emplace_back(node->val);
        }
        int sz = res.size();
        for (int i = 1; i < sz; i += 2) {
            reverse(begin(res[i]), end(res[i]));
        }
        return res;
    }
};
