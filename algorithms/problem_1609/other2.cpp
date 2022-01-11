class Solution {
public:
    vector<int> vals; // Using an array to hold last value for each level.
    bool isEvenOddTree(TreeNode* n, size_t l = 0) {
        if (n == nullptr)
            return true;
        if (n->val % 2 == l % 2)
            return false;
        vals.resize(max(vals.size(), l + 1));
        if (vals[l] != 0 && ((l % 2 && vals[l] <= n->val) || (!(l % 2) && vals[l] >= n->val)))
            return false;
        vals[l] = n->val;
        return isEvenOddTree(n->left, l + 1) && isEvenOddTree(n->right, l + 1);
    }
};