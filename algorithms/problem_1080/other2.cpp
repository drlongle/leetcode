class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum = 0) {
        if(!root)
            return NULL;
        sum += root->val;
        if(!root->left && !root->right) 
            return sum >= limit ? root : NULL;
        root->left = sufficientSubset(root->left, limit, sum);
        root->right = sufficientSubset(root->right, limit, sum);        
        return (root->left || root->right) ? root : NULL;
    }
};
