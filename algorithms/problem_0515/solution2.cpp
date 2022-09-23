class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        vector<vector<TreeNode *>> nodes(2);
        nodes[0].push_back(root);
        int index = 0;
        while (nodes[index].size()) {
            nodes[1 - index].clear();
            int n = numeric_limits<int>::min();
            for (auto node : nodes[index]) {
                n = max(n, node->val);
                if (node->left)
                    nodes[1 - index].push_back(node->left);
                if (node->right)
                    nodes[1 - index].push_back(node->right);
            }
            res.push_back(n);
            index = 1 - index;
        }

        return res;
    }
};
