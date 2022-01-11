/*
Insight: To find the shortest required operations that sum up to x is to find the longest subarray that
sums up to total - x.

Step 1: Calculate the total sum of nums. Mark as total.
Step 2: Initialize two pointers left and right to 0. Initialize an integer current to represent
the sum from nums[left] to nums[right], inclusively. Initialize an integer maxi to record the
maximum length that sums up to total - x.

Step 3: Iterate right form 0 to the end of nums. In each iteration:
Update current.
If current is greater than total - x, move left to left.
If current is equal to total - x, update the maximum length.

Step 4: Return the result.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        int n = nums.size();
        int maxi = -1;
        int left = 0;
        int current = 0;

        for (int right = 0; right < n; right++) {
            // sum([left ,..., right]) = total - x
            current += nums[right];
            // if larger, move `left` to left
            while (current > total - x && left <= right) {
                current -= nums[left];
                left += 1;
            }
            // check if equal
            if (current == total - x) {
                maxi = max(maxi, right - left + 1);
            }
        }
        return maxi != -1 ? n - maxi : -1;
    }
};
