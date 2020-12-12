class Solution {
public:
    TreeNode* sol=NULL;
    int maxDepth=0;
    int postorder(TreeNode* root,int level)
    {
        if(!root)
            return level;
        maxDepth=max(++level,maxDepth);
        int left=postorder(root->left,level);
        int right=postorder(root->right,level);
        if(left==right && left==maxDepth)
            sol=root;
        return max(left,right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        postorder(root,0);
        return sol;
    }
};
