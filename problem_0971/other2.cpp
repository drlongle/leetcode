class Solution {
public:
    bool rec(TreeNode* root) {
        if (!root) return true;
        if (root->val != m_voyage[i++]) {
            return false;
        }
        if (root->left && root->left->val != m_voyage[i]) {
            res.push_back(root->val);
            return rec(root->right) && rec(root->left);
        }
        else
            return rec(root->left) && rec(root->right);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        m_voyage = voyage;
        return rec(root) ? res : vector<int>{-1};
    }

private:
    vector<int> m_voyage;
    vector<int> res;
    int i = 0;
};
