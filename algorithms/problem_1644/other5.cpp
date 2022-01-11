class Solution {
    bool calling(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode* &ans)
    {
        if(root==0)
        {
            return false;
        }
        bool v= calling(root->left,p,q,ans);
        bool c = calling(root->right,p,q,ans);
        if(root->val==p->val || root->val==q->val)
        {
            if(v==true || c==true)
            {
                ans=root;
            }
            return true;
        }
        if(v==true && c==true && ans==0)
        {
            ans=root;
        }

        return v||c;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=0;
        bool v = calling(root,p,q,ans);
        return ans;
    }
};
