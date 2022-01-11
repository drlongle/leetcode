
class Solution {
public:
    struct Info {
        TreeNode* root;
        int count;
    };

    Info bst(TreeNode* root, int lower, int upper) {
        if (!root) return {nullptr, 0};
        if (root->val < upper && root->val > lower) {
            auto ll = bst(root->left, lower, root->val);
            auto rr = bst(root->right, root->val, upper);
            if (ll.root == root->left && rr.root == root->right)
                return {root, ll.count + rr.count + 1};
        }
        auto l = bst(root->left, INT_MIN, INT_MAX);
        auto r = bst(root->right, INT_MIN, INT_MAX);
        return l.count > r.count ? l : r;
    }

    int largestBSTSubtree(TreeNode* root) {
        return bst(root, INT_MIN, INT_MAX).count;
    }
};
