class Solution {
public:
    unordered_set<TreeNode*> s;
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (root == NULL){
            return NULL;
        }
        if (root->right != NULL && s.find(root->right) != s.end()){
            return NULL;
        }

        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);

        s.insert(root);

        return root;
    }
};
