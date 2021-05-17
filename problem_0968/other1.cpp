class Solution {
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root) == 3 ? ans + 1 : ans;
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int val = dfs(node->left) + dfs(node->right);
        if (val == 0) return 3; // parent needs to provide camera
        if (val < 3) return 0;  // one of the children has camera
        ans++;
        return 1;  // add a camera and pass protection to the parant
    }
private:
    int ans = 0;
};
