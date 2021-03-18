class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1, n = nums.size();
        vector<int> up(n, 1), down(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]){
                    up[i] = max(up[i], 1 + down[j]);
                } else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], 1 + up[j]);
                }
                res = max({res, up[i], down[i]});
            }
        }

        return res;
    }
};