class Solution {
public:
    void destory(TreeNode*& root)
    {
	if (root)
	{
            destory(root->left);
            destory(root->right);
            root = NULL;
	}
    }

    bool needRemove(TreeNode* &root, int sum, int limit)
    {
	if (root)
	{
            bool leaf = root->left == NULL && root->right == NULL;
            bool left_remove = needRemove(root->left, sum + root->val, limit);
            bool right_remove = needRemove(root->right, sum + root->val, limit);
            if (left_remove && right_remove)
                destory(root);

            if (root && !leaf && root->left == NULL && root->right == NULL)
                destory(root);

            return left_remove && right_remove;
	}
	return sum < limit;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit)
    {
	needRemove(root, 0, limit);
	return root;
    }
};
