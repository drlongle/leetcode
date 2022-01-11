class Solution {
public:
    int maxPathSumHelper(TreeNode *root, int &res) {
        if (!root) {
            return 0;
        }
              
        int lsum = maxPathSumHelper(root->left, res);
        int rsum = maxPathSumHelper(root->right, res);
        
        int r = root->val;      // root->val;
        r = max(r, r + lsum);   // max (rootv, rootv + lsum)
        r = max(r, r + rsum);   // max (rootv, rootv + lsum, rootv + rsum, rootv + lsum + rsum)
        res = max(r, res);      // max of prior computed result or new one.
        
        return max(root->val, root->val + max(lsum, rsum)); // current max.
    }
    
  
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        
        int res = root->val;
        
        maxPathSumHelper(root, res);
        
        return res;
    }
};

