class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // edge case: short inputs
        if (nums.size() < 2) return nums.size();
        // support variables
        int res = 1, len = nums.size() - 1;
        // parsing nums
        for (int i = 0, diff, val, prev = 0; i < len; i++) {
            // updating diff
            diff = nums[i] - nums[i + 1];
            // ignoring repeated numbers
            if (!diff) continue;
            // updating val
            val = diff > 0 ? 1 : -1;
            // counting the actual flips
            if (val != prev) {
                res++;
                prev = val;
            }
        }
        return res;
    }
};
