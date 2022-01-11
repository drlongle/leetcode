class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_set<int> sums;

        /* dfs, get sum of all sub trees and save into a hashset */
        function<int(TreeNode *)> dfs;
        dfs = [&](TreeNode * node){
            if (node == nullptr){
                return 0;
            }

            int left  = dfs(node->left );
            int right = dfs(node->right);
            int total = node->val + left + right;

            /* save into hash set except root */
            if (node != root) sums.insert(total);
            return total;
        };

        /* true if total sum of the tree is even and on sub-tree's sum == half */
        int totsum = dfs(root);
        return ((totsum & 1) == 0) && (sums.count(totsum / 2));
    }
};
