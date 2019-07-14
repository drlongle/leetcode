struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* dfs(TreeNode* A, int h, int height) {
    if(!A)
        return A;
    if(h == height - 1)
        return A;
    TreeNode* l = dfs(A -> left, h + 1, height);
    TreeNode* r = dfs(A -> right, h + 1, height);
    if(l && r)
        return A;
    if(l)
        return l;     
    return r;
}
    
    int findH(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(findH(root -> left), findH(root -> right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = findH(root);
        return dfs(root, 0, height);
    }
};
