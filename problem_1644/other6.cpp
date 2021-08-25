class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = nullptr;
        dfs(root, p, q);
        return lca;
    }

    TreeNode* dfs(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode *left = dfs(node->left, p, q);
        TreeNode *right = dfs(node->right, p, q);

        if (left != nullptr && right != nullptr) {
            // p is located in one of the subtree and q is located in the other.
            // node is the LCA of p and q.
            lca = node;
            return node;
        }

        if (node == p || node == q) {
            if (left != nullptr || right != nullptr) {
                // node is either p or q and either q or p is located in one of node's subtree.
                // node is the LCA of p and q.
                lca = node;
            }
            return node;
        }

        if (left != nullptr) {
            // Both p and q are in node's left subtree.
            return left;
        }

        if (right != nullptr) {
            // Both p and q are in node's right subtree.
            return right;
        }

        return nullptr;
    }
private:
    TreeNode *lca;
};
