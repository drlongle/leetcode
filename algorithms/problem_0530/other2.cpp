class Solution {
public:
    void recur (TreeNode* root, int& last, int& minm) {
        if (!root) return;
        recur(root->left, last, minm);
        if (abs(root->val-last) < minm) {
            minm = abs(root->val-last);
        }
        last = root->val;
        recur(root->right, last, minm);
    }
    int getMinimumDifference(TreeNode* root) {
        int last = INT_MAX, minm = INT_MAX;
        recur(root, last, minm);
        return minm;
    }
};
