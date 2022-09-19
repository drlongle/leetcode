class Solution {
  public:
    unordered_set<int> table;
    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;
        int val = root->val;
        if (table.count(k - val))
            return true;
        table.insert(val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
