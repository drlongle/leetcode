// C++ solution using lowest common ancestor

class Solution {
public:
    vector<int> sol;
    TreeNode *Parent;
    //level order
    int level(TreeNode *root,TreeNode *target)
    {
        if(root==NULL||root==target)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        pair<TreeNode*,int> p;
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            if(p.first==target)
                return p.second;
            if(p.first->left)
                q.push({p.first->left,p.second+1});
            if(p.first->right)
                q.push({p.first->right,p.second+1});
        }
        return -1;
    }
    TreeNode *LCA(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root==NULL)
            return NULL;
        if(root==p||root==q)
            return root;
        TreeNode *left=LCA(root->left,p,q);
        TreeNode *right=LCA(root->right,p,q);
        if(left!=NULL&&right!=NULL)
            return root;
        return (right==NULL)?left:right;
    }
    int dist(TreeNode *a,TreeNode *b)
    {
        return (level(Parent,a)+level(Parent,b)-2*level(Parent,LCA(Parent,a,b)));
    }
    void helper(TreeNode *root,TreeNode *target,int K)
    {
        if(root==NULL)
            return;
        if(dist(root,target)==K)
            sol.push_back(root->val);
        helper(root->left,target,K);
        helper(root->right,target,K);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(root==NULL)
            return {};
        Parent=root;
        helper(root,target,K);
        return sol;
    }
};
