class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        return BinarySearchMissingNumber(nums, 0, nums.size() - 1, k);
    }

    int BinarySearchMissingNumber(vector<int>& nums, int left, int right, int k) {

        // Base case
        if (right - left + 1 == 2) {
            int expected_elements = nums[right] - nums[left] + 1;
            // Between left and right
            int missing_elements = expected_elements - 2;
            if (k > missing_elements) {
                k -= missing_elements;
                return nums[right] + k;
            } else {
                return nums[left] + k;
            }
        }

        int middle = left + (right - left) / 2;
        // Missing elements on the left [left, middle]
        int expected_elements_left = nums[middle] - nums[left] + 1;
        int missing_elements_left = expected_elements_left - (middle - left + 1);
        if (missing_elements_left >= k) {
            return BinarySearchMissingNumber(nums, left, middle, k);
        } else {
            return BinarySearchMissingNumber(nums, middle, right, k - missing_elements_left);
        }
    }
};
