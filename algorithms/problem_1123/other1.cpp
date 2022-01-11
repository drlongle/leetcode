/*
If left subtree height is greater, then the result is whatever returned by the left as it has highest depth elements.
Similarly if right subtree height is greater, then the result is whatever returned by the right as it has highest depth elements.
If heights of both left and right subarray are equal then the current node is the common ancestors of the deepest leaves.
*/
struct Node{
    TreeNode* result;
    int height;
};

class Solution {
public:
    Node depth(TreeNode* root){
        if(root==NULL) return {NULL,0};
        Node L=depth(root->left);
        Node R=depth(root->right);
        int new_height=max(L.height,R.height)+1;
        if(L.height>R.height) return {L.result,new_height};
        else if(L.height<R.height) return {R.result,new_height};
        else return {root,new_height};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return depth(root).result;
    }
};

