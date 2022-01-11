// For going forward - using a stack.
// For going back, storing traversed values in the list and remember the position.

class BSTIterator {
public:
    stack<TreeNode*> path;
    vector<int> vals;
    int pos = -1;
    void traverseLeft(TreeNode *root) {
        for (; root != nullptr; root = root->left)
            path.push(root);
    }
    BSTIterator(TreeNode* root) { traverseLeft(root); }
    bool hasNext() { return pos + 1 < vals.size() || !path.empty(); }
    int next() {
        if (++pos == vals.size()) {
            auto cur = path.top();
            path.pop();
            traverseLeft(cur->right);
            vals.push_back(cur->val);
        }
        return vals[pos];
    }
    bool hasPrev() { return pos > 0; }
    int prev() { return vals[--pos]; }
};
