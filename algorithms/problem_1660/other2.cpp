class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<int, TreeNode*> mp;
        queue<TreeNode*> q;
        mp[root->val] = NULL;
        q.push(root);

        while (!q.empty()) {
            TreeNode* n = q.front(); q.pop();

            if (n->left) {
                mp[n->left->val] = n;
                q.push(n->left);
            }

            if (n->right) {
                if (mp.find(n->right->val) != mp.end()) {
                    TreeNode* parent = mp[n->val];
                    if (parent->left && parent->left->val == n->val) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                    break;
                }
                mp[n->right->val] = n;
                q.push(n->right);
            }
        }

        return root;
    }
};
