class Solution {
public:
    void upside(TreeNode* root, TreeNode* parent, TreeNode** newRoot)
    {
        //Base case
        if(!root)
            return;

        //Recur on the left side.
        upside(root->left, root, newRoot);

        //Set the new Root pointer: The Leftmost node
        if(!*newRoot)
            *newRoot = root;

        //Make the right node as parent.
        root->right = parent;

        //If parent's right exists, make it as Left.
        if(parent && parent->right )
            root->left = parent->right;
        else
            root->left = NULL;
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* newRoot = NULL;
        //recurse and update the tree pointers.
        upside(root, NULL, &newRoot);

        return newRoot;
    }
};
