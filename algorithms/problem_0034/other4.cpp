class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (l == nums.size() || nums[l] != target) ? vector<int>{-1, -1} : vector<int>{l, r - 1};
    }
};
