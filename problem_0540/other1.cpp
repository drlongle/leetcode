class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        if (l < h) {
            if (nums[l] != nums[l + 1]) {
                return nums[l];
            }
            if (nums[h] != nums[h - 1]) {
                return nums[h];
            }
        } else {
            return nums[0];
        }
        auto index = 0;
        while (l < h) {
            int mid = (l + h) / 2;
            if ((mid % 2) != 0) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 1;
            } else if (nums[mid] == nums[mid - 1]) {
                h = mid - 1;
            } else {
                index = mid;
                break;
            }
        }
        return  index == 0 ? nums[l] : nums[index];
    }
};
