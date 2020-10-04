class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
        int ret = 0;
        if(root->val>=L&&root->val<=R) ret+=root->val;
        if(root->val>L) ret+=rangeSumBST(root->left,L,min(R,root->val));
        if(root->val<R) ret+=rangeSumBST(root->right,max(L,root->val),R);
        return ret;
    }
};