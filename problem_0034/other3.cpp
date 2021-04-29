class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto [l, r] = equal_range(begin(nums), end(nums), target);
        if (l == end(nums) || *l != target)
            return {-1, -1};

        int i = l - begin(nums), j = r - 1 - begin(nums);
        return {i, j};
    }
};
