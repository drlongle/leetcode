class Solution {
  public:
    int sum = 0;
    void visit(TreeNode *node) {
        if (!node)
            return;
        int index = path.size() - 2;
        if (index >= 0 && path[index] % 2 == 0)
            sum += node->val;
        path.push_back(node->val);
        visit(node->left);
        visit(node->right);
        path.pop_back();
    }
    vector<int> path;
    int sumEvenGrandparent(TreeNode *root) {

        visit(root);
        return sum;
    }
};
