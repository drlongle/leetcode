struct ResultType {
    int size, lower, upper;
};

class Solution {
private:
    int res = 0;
public:
    int largestBSTSubtree(TreeNode* root) {
        helper(root);

        return res;
    }

    ResultType helper(TreeNode* root) {
        if (root == nullptr) return (ResultType){0, 0, 0};

        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        if ((left.size == -1 || right.size == -1) ||
            root->val <= left.upper && left.size != 0 ||
            root->val >= right.lower && right.size != 0) return (ResultType){-1, 0, 0};

        res = max(res, 1 + left.size + right.size);

        return (ResultType) {
                1 + left.size + right.size,
                left.size  ? left.lower : root->val,
                right.size ? right.upper : root->val
        };
    }
};
