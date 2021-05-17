class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 1) res++;
        return res;
    }

private:
    int res = 0;

    /*
    -1 : If we are already covered by a camera
    0 : we have a camera
    1 : we need a camera.
    */

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 1 || right == 1) {
            res++;
            return -1;
        }

        else if (left == -1 || right == -1)
            return 0;

        else return 1;
    }
};
