class Solution {
public:    
    void helper(TreeNode* root, vector<int>& result) {
        if (!root)
            return;
        helper(root->left,  result);
        result.push_back(root->val);
        helper(root->right, result);
    }
        
    int getMinimumDifference(TreeNode* root) {
        vector<int> result;        
        helper(root, result);
        int diff = INT_MAX;        
        for (int i = 1; i < result.size(); i++){
            diff = min(diff, result[i]-result[i-1]);        
        }
        return diff;
    }
};
