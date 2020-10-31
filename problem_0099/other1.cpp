
class Solution {
public:
    void dfs(TreeNode* root, TreeNode* left, TreeNode* right, bool& swapped)
    {
        if(root==NULL)
            return;

        if(left != NULL && root->val < left->val)
        {
            swapped = true;
            std::swap(root->val, left->val);
        }
        else if(right != NULL && root->val > right->val)
        {
            swapped = true;
            std::swap(root->val, right->val);
        }

        dfs(root->left, left, root, swapped);
        dfs(root->right, root, right, swapped);
    }

    void recoverTree(TreeNode* root) {
        bool swapped = true;
        while(swapped)
        {
            swapped = false;
            dfs(root, NULL, NULL, swapped);
        }
    }
};
