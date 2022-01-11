class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            if(curr==NULL)
                break;
            q.push(curr->left);
            q.push(curr->right);
        }
        if(q.empty())
            return true;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            if(curr)
                return false;
        }
        return true;
    }
};
