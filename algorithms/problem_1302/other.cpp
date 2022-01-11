class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int resp = 0; 
        if (root == NULL) return resp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            while(n) {
                TreeNode *temp = q.front();
                q.pop();
                sum+=temp->val;
                if (temp->left)q.push(temp->left);                
                if (temp->right)q.push(temp->right);       
                n--;         
            }
            resp = sum;
        } 
        return resp; 
    }
};
