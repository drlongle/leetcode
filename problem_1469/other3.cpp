class Solution {
public:
    vector<int> lonelyNodes;
    vector<int> getLonelyNodes(TreeNode* root) {
        getLonelyNodes_aux(nullptr, root);
        return lonelyNodes;
    }

private:
    void getLonelyNodes_aux(TreeNode* parent, TreeNode* root)
    {
        if(root == nullptr)
            return;

        if(parent != nullptr)
        {
            if( (parent->left == nullptr) ||
            (parent->right == nullptr))
            {
                lonelyNodes.push_back(root->val);
            }
        }
        getLonelyNodes_aux(root, root->left);
        getLonelyNodes_aux(root, root->right);
    }
};
