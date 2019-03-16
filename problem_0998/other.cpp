TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
  if (root == nullptr || val > root->val) {
    auto n = new TreeNode(val);
    n->left = root;
    return n;
  }
  root->right = insertIntoMaxTree(root->right, val);
  return root;
}

