class Solution {
public:    
    TreeNode* BstInsert(TreeNode*& root, int val){
        if(!root){    
            root = new TreeNode(val);
        }else{  
            if(val < root->val)  
                root->left  = BstInsert(root->left, val);   
            else if(root->val < val)  
                root->right = BstInsert(root->right, val);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        
        for (auto val : preorder)
            BstInsert(root, val);
        
        return root;
    }
};
