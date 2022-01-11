class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,TreeNode*> > q;
        unordered_set<TreeNode*> found;

        q.push_back({nullptr,root});
        found.insert(root);

        while(!q.empty()) {

            auto top = q.front();
            q.pop_front();

            if((top.second)->left) {
                q.push_back({top.second,(top.second)->left});
                found.insert(top.second->left);
            }

            if((top.second)->right) {
                if(found.find((top.second)->right) != found.end()) {
                    if((top.first)->left == top.second) {
                        (top.first)->left = nullptr;
                    } else {
                        (top.first)->right = nullptr;
                    }

                    return root;
                }

                q.push_back({top.second,(top.second)->right});
                found.insert(top.second->right);
            }
        }

        return nullptr;
    }
};
