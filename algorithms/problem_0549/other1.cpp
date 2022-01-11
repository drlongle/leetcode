class Solution {
public:
    int maxval=0;
    int longestConsecutive(TreeNode* root) {
        util(root);
        return maxval;
    }

    pair<int, int> util(TreeNode* root) { //ending at root->val, begin at root->val
        if(!root) return{0,0};
        auto l = util(root->left);
        auto r = util(root->right);

        pair<int, int> ans; ans.first=1; ans.second = 1;
        if(root->left && root->left->val+1 == root->val) ans.first = l.first+1;
        else if(root->left && root->left->val == root->val+1) ans.second = l.second+1;

        if(root->right && root->right->val+1 == root->val) ans.first = max(ans.first, r.first+1);
        else if(root->right && root->right->val == 1+root->val) ans.second = max(ans.second, r.second+1);
        
        maxval = max(maxval, ans.first+ans.second-1);
        return ans;
    }
};
