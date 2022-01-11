class Solution {
public:
    TreeNode* minElement(TreeNode* root){
        if(root==NULL)return NULL;
        TreeNode *temp=root;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //3 cases to be considered
        if(root==NULL)return NULL;
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else if(key>root->val)
            root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL){
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            if(root->right==NULL){
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            TreeNode *nx=minElement(root->right);
            root->val=nx->val;
            root->right=deleteNode(root->right,nx->val);
            return root;
        }
        return root;
    }
};

