class BSTIterator {
public:
    BSTIterator(TreeNode* ro): root(ro)
    {
    }

    TreeNode* root;
    int curr = INT_MIN;

    bool hasNext() {
        auto node = root;
        while (node) {
            if (node->val > curr)
                return true;
            node = node->right;
        }
        return node;
    }

    int next() {
        auto node = root;
        int res = INT_MAX;

        while (node) {
            if (node->val <= curr)
                node = node->right;
            else {
                res = min(res, node->val);
                node = node->left;
            }
        }
        return curr = res;
    }

    bool hasPrev() {
        auto node = root;
        while (node) {
            if (node->val < curr)
                return true;
            node = node->left;
        }
        return node;
    }

    int prev() {
        auto node = root;
        int res = INT_MIN;
        while (node) {
            if (node->val >= curr)
                node = node->left;
            else{
                res = max(res, node->val);
                node = node->right;
            }
        }
        return curr = res;
    }
};
