class Solution {
public:
    bool isLeaf(TreeNode *root){
        return root->left == NULL && root->right == NULL;
    }
    void rightboundaryandleaves(TreeNode *root, bool is_boundary, vector<int> &res){
        if (root != NULL) {
            rightboundaryandleaves(root->left, is_boundary && root->right == NULL, res);
            rightboundaryandleaves(root->right, is_boundary,res);
            if (is_boundary || isLeaf(root))
                res.push_back(root->val);
        }
    }

    void leftboundaryandleaves(TreeNode *root, bool is_boundary, vector<int> &res){
        if (root != NULL) {
            if (is_boundary || isLeaf(root))
                res.push_back(root->val);
            leftboundaryandleaves(root->left, is_boundary,res);
            leftboundaryandleaves(root->right, is_boundary && root->left == NULL, res);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return {};
        if (root)
            res.push_back(root->val);
        leftboundaryandleaves(root->left, true, res);
        rightboundaryandleaves(root->right, true, res);

        return res;
    }
};