class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int miss = nums[n-1] - nums[0] - n + 1;
        if (k > miss) {
            return nums[n-1] + k - miss;
        }
        int left = 0, right = n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int missing = nums[mid] - nums[left] - mid + left;
            if (missing >= k) {right = mid;}
            else {
                left = mid;
                k -= missing;
            }
        }
        return nums[left] + k;
    }
};
