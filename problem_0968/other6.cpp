class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int count{0};
        dfs(root, count, root);
        return count;
    }

    // 1: covered, no camera
    // 2: covered, camera
    // 3: not covered, no camera
    int dfs(TreeNode* root, int& count, TreeNode* head) {

        if(!root) return 1;
        if(!root->left && !root->right) return 3;

        int a{dfs(root->left, count, head)}, b{dfs(root->right, count, head)};

        if(a == 3 || b == 3) {
            ++count;
            return 2;
        }

        if(a == 1 && b == 1) {
            if(root == head) ++count;
            return 3;
        }

        return 1;
    }
};
