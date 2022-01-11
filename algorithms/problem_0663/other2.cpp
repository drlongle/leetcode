class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        std::set<int> sums;
        int rootSum = populateSum(root, sums, true);
        if (rootSum % 2 != 0) return false;
        return sums.find(rootSum / 2) != sums.end();
    }

    int populateSum(TreeNode* node, std::set<int>& sums, bool isRoot) {
        if (node == nullptr) return 0;
        int left = populateSum(node->left, sums, false);
        int right = populateSum(node->right, sums, false);
        int sum = node->val + left + right;
        if (!isRoot) sums.insert(sum);
        return sum;
    }
};
