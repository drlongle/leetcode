class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(NULL == root)
            return true;
        queue<TreeNode* > q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                root=q.front();
                q.pop();
                if(root==NULL){
                    flag=true;
                    continue;
                }
                if(flag)
                    return false;
                q.push(root->left);
                q.push(root->right);
            }

        }
        return true;
    }
};
