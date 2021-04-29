class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target_, int K) {
        vector<int> nums;
        inorderTraverse(root, nums);
        auto cmp_ = [&](const int& a, const int& b) {return abs((double) a - target_) < abs((double) b - target_); };
        nth_element(nums.begin(), nums.begin() + K-1, nums.end(), cmp_);
        return vector<int>(nums.begin(),nums.begin()+K);
    }
private:
    void inorderTraverse(TreeNode* root, vector<int>& nums) {
        if(root == nullptr) return;
        inorderTraverse(root->left, nums);
        nums.push_back(root->val);
        inorderTraverse(root->right, nums);
    }
};
