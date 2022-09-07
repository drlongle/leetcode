class Solution {
  public:
    string tree2str(TreeNode *root) {
        if (!root)
            return "";

        string a = tree2str(root->left);
        string b = tree2str(root->right);

        string ans = to_string(root->val);
        if (b.size() || a.size())
            ans = ans + '(' + a +
                  ')'; // if b.size() is not zero means we need to correctly
                       // identify right so add serialization for left
        if (b.size())
            ans = ans + '(' + b + ')';

        return ans;
    }
};
