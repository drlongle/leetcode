class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        set<TreeNode*> visited;
        // reverse level order
        queue<TreeNode**> q({&root});
        while (!q.empty()) {
            visited.clear();

            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode** ppNode = q.front();
                q.pop();

                if ((*ppNode)->right) {
                    if (visited.find((*ppNode)->right) != visited.end()) {
                        (*ppNode) = nullptr;
                        return root;
                    }
                    q.push(&((*ppNode)->right));
                }
                if ((*ppNode)->left) {
                    q.push(&((*ppNode)->left));
                }
                visited.insert(*ppNode);
            }
        }

        return root;
    }
};
