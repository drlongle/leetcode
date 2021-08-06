class Solution {
public:

    map<TreeNode*, vector<TreeNode*>> children;
    vector<int> getLonelyNodes(TreeNode* root) {
        bfs(root);
        vector<int> ans;
        for (auto x : children) {
            if (x.second.size() == 1) {
                ans.push_back(x.second[0]->val);
            }
        }
        return ans;
    }


    void bfs(TreeNode* root) {
        if (!root) {
            return;
        }
        queue<TreeNode*> q;
        map<TreeNode*, int> visited;

        q.push(root);
        while (!q.empty()) {
            TreeNode* v = q.front();
            q.pop();

            if (v != NULL && v->left != NULL) {
                children[v].push_back(v->left);
                q.push(v->left);
            }

            if (v != NULL && v->right != NULL) {
                children[v].push_back(v->right);
                q.push(v->right);
            }
        }
    }
};
