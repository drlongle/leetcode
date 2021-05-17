class Solution {
public:
    int count=0;
    set<TreeNode*>s;
    void dfs(TreeNode* r,TreeNode *p)
    {
        if(!r)
            return;
        dfs(r->left,r);
        dfs(r->right,r);
        if (p==NULL&&s.find(r)==s.end()||s.find(r->left)==s.end()||s.find(r->right)==s.end())
        {
            count++;
            s.insert(r);
            s.insert(r->left);
            s.insert(r->right);
            s.insert(p);
        }
    }
    int minCameraCover(TreeNode* root) {
        s.insert(NULL);
        dfs(root,NULL);
        return count;
    }
};
