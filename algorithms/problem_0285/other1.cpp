class Solution {
public:
    TreeNode *answer=nullptr,*prev=nullptr;
    void inorder(TreeNode *root,TreeNode *p){
        if(!root || answer) return;
        inorder(root->left,p);
        if(prev==p) answer=root;
        prev=root;
        inorder(root->right,p);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root,p);
        return answer;
    }
};