class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*>ans(2);
        if(root==0)
        {
            return ans;
        }
        if(root->val > target)
        {
            ans[1]=root;
            vector<TreeNode*>p = splitBST(root->left,target);
            ans[0]=p[0];
            ans[1]->left=p[1];
        }
        else if(root->val <= target)
        {
            ans[0]=root;
            vector<TreeNode*>p = splitBST(root->right,target);
            ans[0]->right=p[0];
            ans[1]=p[1];
        }
        return ans;
    }
};
