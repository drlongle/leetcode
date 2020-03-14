class Solution {
public:
    vector<int>v;
    void traverse(TreeNode* root){
        if(!root)
            return;
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        int mini = INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            mini = min(mini,v[i+1]-v[i]);
        }
        return mini;
    }
};
