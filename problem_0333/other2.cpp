using pi=vector<int>;
int gmax;

pi dfs(TreeNode *root)
{
    if(!root)
        return {0,INT_MIN,INT_MAX};

    pi p1=dfs(root->left);
    pi p2=dfs(root->right);

    if(root->val<=p1[1]||root->val>=p2[2])       //subtree is not BST
        return {0,INT_MAX,INT_MIN};

    int curr_sum=p1[0]+p2[0]+1;
    int curr_max=max(root->val,max(p1[1],p2[1]));
    int curr_min=min(root->val,min(p1[2],p2[2]));

    gmax=max(gmax,curr_sum);

    return {curr_sum,curr_max,curr_min};
}

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {

        if(!root)return 0;
        gmax=1;
        dfs(root);
        return gmax;
    }
};
