class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;   
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            while(node) {
                res.push_back(node->val);
                st.push(node->right);
                node = node->left;
            }
        }
        return res;
    }
};

