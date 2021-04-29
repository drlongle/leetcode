class Solution {
private:
    vector<int> res;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> st; TreeNode* cur = root;

        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur); cur = cur->left;
            }

            cur = st.top(); st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }

        return helper(target, k, res);
    }

    vector<int> helper(double target, int k, vector<int>& nums) {
        vector<int> res;
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        int left = right - 1;

        while (k) {
            if (left >= 0 && right < nums.size()) {
                if (target - nums[left] < nums[right] - target) {
                    res.push_back(nums[left--]);
                } else {
                    res.push_back(nums[right++]);
                }
            } else {
                if (left < 0 && right < nums.size()) res.push_back(nums[right++]);
                else if (right >= nums.size() && left >= 0) res.push_back(nums[left--]);
            }
            k--;
        }

        return res;
    }
};
