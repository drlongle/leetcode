
class Solution {
public:
    void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
        if (n == nullptr) return;
        s.push(n);
        pushLeft(s, n->left);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        pushLeft(s1, root1);
        pushLeft(s2, root2);
        while (!s1.empty() || !s2.empty()) {
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
                s1.top()->val < s2.top()->val ? s1 : s2;
            auto n = s.top(); s.pop();
            res.push_back(n->val);
            pushLeft(s, n->right);
        }
        return res;
    }
};
