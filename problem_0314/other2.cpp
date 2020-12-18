class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int,int>>> m;
        function<void(TreeNode*, int, int)> dfs;
        dfs = [&m, &dfs](TreeNode* node, int x, int y) {
            if (!node) return;
            m[x].push_back({y, node->val});
            dfs(node->left, x - 1, y - 1);
            dfs(node->right, x + 1, y - 1);
        };
        dfs(root, 0, 0);
        // Preorder traversal => nodes of the same (x, y) are added from left to right by default
        // We need only sort by decreasing y
        vector<vector<int>> results;
        vector<int> result;
        for (auto& [x, p] : m) { // p is unused
            sort(m[x].begin(), m[x].end(), [](const auto& p1, const auto& p2) {
                return p1.first > p2.first;
            });
            for (auto& [y, v] : m[x]) result.push_back(v);
            results.push_back(move(result)); // std::move invalidates result
        }

        return results;
    }
};
