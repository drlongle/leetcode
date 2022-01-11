class Solution {
public:

    int find_first(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, res = INT_MAX;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (nums[mid] == target) {
                res = mid;
                hi = mid -1;
            } else if (nums[mid] > target)
                hi = mid -1;
            else
                lo = mid + 1;
        }
        return res == INT_MAX ? -1: res;
    }

    int find_last(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, res = INT_MAX;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (nums[mid] == target) {
                res = mid;
                lo = mid + 1;
            } else if (nums[mid] > target)
                hi = mid -1;
            else
                lo = mid + 1;
        }
        return res == INT_MAX ? -1: res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        res[0] = find_first(nums,target);
        if (res[0] < 0)
            return res;
        res[1] = find_last(nums,target);
        return res;
    }
};