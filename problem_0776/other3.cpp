class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {

        vector <TreeNode*> temp;

        if (root==NULL) {
            temp = vector <TreeNode*> ({NULL, NULL});
            return temp;
        }

        if (root->val<=V) {
            temp =splitBST(root->right, V);
            root->right = temp[0];
            temp[0]=root;
        } else {
            temp =splitBST(root->left, V);
            root->left = temp[1];
            temp[1]=root;
        }
        return temp;
    }
};
