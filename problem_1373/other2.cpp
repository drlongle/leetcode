class Solution {
public:
    bool maxSumBST_(TreeNode* root, int& sum_val) {
	if (!root) return true;

	bool new_bst = true;
	int new_val = root->val;
	if (root->left && root->val <= root->left->val) new_bst = false;
	if (root->right && root->val >= root->right->val) new_bst = false;

	bool left = maxSumBST_(root->left, sum_val);
	bool right = maxSumBST_(root->right, sum_val);

	if (left && right && new_bst) {
            if (root->left) new_val += root->left->val;
            if (root->right) new_val += root->right->val;
            root->val = new_val;
            sum_val = max(sum_val, new_val);
            return true;
	}


	return false;
    }

    int maxSumBST(TreeNode* root) {
	int sum_val = 0;
	maxSumBST_(root, sum_val);
	return sum_val;
    }
};
