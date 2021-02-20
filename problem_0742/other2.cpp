class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        if (root == nullptr) return 0;
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        TreeNode* kNode = nullptr;
        dfs(root, k, kNode, nullptr, graph);
        return bfs(kNode, graph);
    }

    void dfs(TreeNode* root, int k, TreeNode*& kNode, TreeNode* parent,
             unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (root == nullptr) return;
        if (root->val == k) kNode = root;
        if (parent != nullptr) {
            graph[root].push_back(parent);
            graph[parent].push_back(root);
        }
        dfs(root->left, k, kNode, root, graph);
        dfs(root->right, k, kNode, root, graph);
    }

    int bfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        queue<TreeNode*> q({root});
        unordered_set<TreeNode*> seen({root});

        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node->left == nullptr &&
                node->right == nullptr) {
                return node->val;
            }
            for (auto nei : graph[node]) {
                if (seen.count(nei) > 0) continue;
                q.push(nei);
                seen.insert(nei);
            }
        }

        return -1;
    }
};
