class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* ans=NULL;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root){return ans;}
        inorderSuccessor(root->left,p);
        if(prev!=NULL && p->val==prev->val ){
            ans=root;
        }
        prev=root;
        inorderSuccessor(root->right,p);
        return ans;
    }
};
