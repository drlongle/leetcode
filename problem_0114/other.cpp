class Solution {
public:
    
    // Iteration
    void flatten_(TreeNode* root) {
        while(root) {
            if( ! root->left) {
                root = root->right;
                continue;
            }
            
            TreeNode* prev = root->left;
            while(prev->right) {
                prev = prev->right;
            }
            
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            
            // Move to the right tree and continue doing the same
            root = root->right;
        }
    }
    
    // Similar way in a recursive manner using post-order traversal (from bottom to the up)
    void flatten(TreeNode* root) {
        if( ! root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* rightSave = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        // The key part:
        // Since root->left was already flattened previously
        // just go the right most node of root's left tree and point it to the saved right child
        while(root->right) {
            root = root->right;
        }
        root->right = rightSave;
    }
    
};

