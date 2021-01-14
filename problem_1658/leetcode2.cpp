/*
Algorithm

Step 1: Calculate the total sum of nums.

Step 2: Initialize two pointers left and right to 0. Initialize an integer current to represent the
sum from nums[0] to nums[left-1] and from nums[right+1] to nums[last]. Initialize an integer mini to
record the minimum length that sums up to x

Step 3: Iterate right form 0 to the end of nums. In each iteration:

Update current.
If current is smaller than x, move left to left.
If current is equal to x, update the maximum length.

Step 4: Return the result.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int current = 0;
        for (int num : nums) {
            current += num;
        }
        int n = nums.size();
        int mini = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // sum([0,..,left) + (right,...,n-1]) = x
            current -= nums[right];
            // if smaller, move `left` to left
            while (current < x && left <= right) {
                current += nums[left];
                left += 1;
            }
            // check if equal
            if (current == x) {
                mini = min(mini, (n - 1 - right) + left);
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};