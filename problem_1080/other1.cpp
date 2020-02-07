class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        //When we arrive at a leaf, we check if the sum accumulated is equal to that node's value
        //In case it is not, we return nullptr to signal this node will be out of the resulting tree
        if(root->left == nullptr && root->right == nullptr)
        {
            if(root->val < limit)
            {
                return nullptr;
            }
            else
            {
                return root;
            }
        }
        
        //We traverse the tree left and right, effectively solving the problem for the subtree 
        if(root->left != nullptr)
        {
            root->left = sufficientSubset(root->left, limit - root->val);
        }
        
        if(root->right != nullptr)
        {
            root->right = sufficientSubset(root->right, limit - root->val);
        }
        
        //If, after solving the subproblems for left and right subtrees we realise that both paths have been cut out, it means our node is also insufficient and should be cut out.
        if(root->left == nullptr && root->right == nullptr)
            return nullptr;
        
        //Otherwise our node shall be preserved
        return root;
    }
};
