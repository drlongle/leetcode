class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> nodeSet(begin(nodes), end(nodes));
        return lca(root, nodeSet);
    }

    TreeNode* lca(TreeNode* root, unordered_set<TreeNode*> &nodes) {
        if (!root || nodes.count(root)) return root;
        TreeNode* l = lca(root->left, nodes), *r = lca(root->right, nodes);
        return l ? r ? root : l : r;
    }
};
