class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d,int level = 2) {
        if(root == nullptr)
            return nullptr;
        if( d == 1 ){
            root = new TreeNode(v,root,nullptr);
        }
        else if(d == level){
            root->left  = new TreeNode(v,root->left,nullptr);
            root->right = new TreeNode(v,nullptr,root->right);
        }else{
            root->left  = addOneRow( root->left ,v, d,level+1);
            root->right = addOneRow( root->right,v, d,level+1);
        }

        return root;
    }
};
