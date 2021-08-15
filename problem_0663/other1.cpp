class Solution {
    unordered_map<int, int>mp;
    int storeSum(TreeNode* root) {
        if (!root) return 0;
        int total = root->val + storeSum(root->left) + storeSum(root->right);
        mp[total]++;
        return total;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        if (!root) return true;
        int sum = storeSum(root);
        if (sum == 0)
            return mp[sum] > 1;
        return sum % 2 == 0 && mp.count(sum/2);
    }
};
