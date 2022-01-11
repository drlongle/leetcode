class Solution {
public:
    int maxi = -1;
    TreeNode* ans = NULL;
    int func(TreeNode* root, int level){
        int left = level;
        int right = level;
        if(root->left != NULL){
            left = func(root->left, level+1);
        }
        if(root->right != NULL){
            right = func(root->right, level+1);
        }
        int ret = max(left, right);
        if(left >= maxi && right >= maxi){
            ans = root;
            maxi = ret;
        }
        return ret;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        func(root, 1);
        return ans;
    }
};
