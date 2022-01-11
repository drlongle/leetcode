class Solution {

    pair<TreeNode*,int> lowestCommonAncestorUtil(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL)
            return {NULL,0};

        auto l = lowestCommonAncestorUtil(root->left,p,q);
        auto r = lowestCommonAncestorUtil(root->right,p,q);

        if(l.second == 2)
            return l;

        if(r.second == 2)
            return r;

        return {root,l.second + r.second + (root == p || root == q)};
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        auto res = lowestCommonAncestorUtil(root,p,q);

        return res.second == 2 ? res.first : NULL;
    }
};
